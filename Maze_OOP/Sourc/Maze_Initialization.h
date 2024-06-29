#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;

const int row = 21, colm = 21;

class Maze_Initialization
{
private:
	sf::Sprite maze_spr[row][colm];
	sf::Texture wall_Texture, sideWall_Texture, chest_Texture;
	sf::FloatRect wall_Bounds , sideWall_Bounds;

public:
	sf::FloatRect bounds[row][colm];
	char arr[row][colm];
	Maze_Initialization();
	void initialize();

	void draw(sf::RenderWindow& window);

};