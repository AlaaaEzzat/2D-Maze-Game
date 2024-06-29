#include "Maze_Initialization.h"

Maze_Initialization::Maze_Initialization() 
{
	this->wall_Texture.loadFromFile("Environment/wall3.png");
	this->sideWall_Texture.loadFromFile("Environment/WallTst.png");
	this->chest_Texture.loadFromFile("Chest/Chests1.png");

	wall_Bounds.height = 3.2;
	wall_Bounds.width = 2.7;
	wall_Bounds.top = 72;
	wall_Bounds.left = 67;

	sideWall_Bounds.height = 3.1;
	sideWall_Bounds.width = 6;
	sideWall_Bounds.top = 75;
	sideWall_Bounds.left = 87;
}

void Maze_Initialization::initialize() {

	std::ifstream sin;
	sin.open("Mazes/Maze6.txt");

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < colm; j++) {
			sin >> arr[i][j];
			if (arr[i][j] == 'w') {

				this->maze_spr[i][j].setPosition(j * 55.f, i * 65.f);
				this->maze_spr[i][j].setTexture(this->wall_Texture);
				this->maze_spr[i][j].setOrigin(100, 70);
				bounds[i][j] = maze_spr[i][j].getGlobalBounds();

				bounds[i][j].height /= wall_Bounds.height;
				bounds[i][j].width /= wall_Bounds.width;
				bounds[i][j].top += wall_Bounds.top;
				bounds[i][j].left += wall_Bounds.left;

			}
			else if (arr[i][j] == 'q')
			{
				this->maze_spr[i][j].setPosition(j * 55.f, i * 65.f);
				this->maze_spr[i][j].setTexture(this->sideWall_Texture);
				this->maze_spr[i][j].setOrigin(100, 73);
				bounds[i][j] = maze_spr[i][j].getGlobalBounds();

				bounds[i][j].height /= sideWall_Bounds.height;
				bounds[i][j].width /= sideWall_Bounds.width;
				bounds[i][j].top += sideWall_Bounds.top;
				bounds[i][j].left += sideWall_Bounds.left;
			}
			else 
			{
				if (arr[i][j] == 't') {

					this->maze_spr[i][j].setPosition(j * 46, i * 63);
					this->maze_spr[i][j].setTexture(this->chest_Texture);
					bounds[i][j] = maze_spr[i][j].getGlobalBounds();

					bounds[i][j].height /= 7;
					bounds[i][j].width /= 7;
					bounds[i][j].top += 60;
					bounds[i][j].left += 55;
				}
			}
		}
	}
}

void Maze_Initialization::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < colm; j++) {

			if (arr[i][j] == 'q' || arr[i][j] == 'w' || arr[i][j] == 't') {
				window.draw(maze_spr[i][j]);

			}
		}
	}
}