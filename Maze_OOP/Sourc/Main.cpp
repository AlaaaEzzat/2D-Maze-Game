#include <SFML/Graphics.hpp>
#include <iostream>
#include "Maze_Initialization.h"
#include "Player.h"
#include "Camera_System.h"


void Collision_Detection(sf::FloatRect player_Bounds, sf::FloatRect Other_Bounds[row][colm], char arr[row][colm], bool& can_move, bool& won);
int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

	//set Text
	sf::Font font;
	font.loadFromFile("arial/arial.ttf");

	sf::Text text;
	text.setFont(font);
	text.setPosition(400, 400);
	text.setString("Congratulations You Found the Treasure!");

	//colision Attributes
	float speed = 200;
	bool can_move = true , won = false;

	//time calculation
	sf::Clock clock;
	float deltaTime = 0;
	float time = 0;

	//set maze Background
	sf::Texture background_Texture;
	sf::Sprite background_Sprite;
	background_Texture.loadFromFile("Environment/Window_Texture2.png");
	background_Sprite.setTexture(background_Texture);
	background_Sprite.setPosition(-400, -400);


	//initialize the maze
	Maze_Initialization maze;
	maze.initialize();

	//initialize the player and set speed
	Player player(speed);

	// initialize the camera system
	Camera cam(window);


	while (window.isOpen())
	{

		float currentTime = clock.getElapsedTime().asSeconds();
		deltaTime = currentTime - time;
		time = currentTime;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		window.clear(sf::Color(37, 37, 37));
		window.draw(background_Sprite);

		//Handel player inputs
		player.handleInput();


		//Handel player Colisions
		Collision_Detection(player.get_Bounds(), maze.bounds, maze.arr, can_move, won);

		// check if the player can move based on the colisions
		if (can_move == true) 
		{
			player.move(deltaTime);
		}

		//win condition
		if (won == false) {
			player.Update_Bounds();

			cam.check_Camera_Limits(player.get_Player_Position());
			cam.move_Camera(window);
			maze.draw(window);
			player.draw(window);
		}
		else
		{
			window.clear(sf::Color(37, 37, 37));
			text.setPosition(sf::Vector2f(window.getView().getCenter().x -250 , window.getView().getCenter().y));
			window.draw(text);
		}

		window.display();
	}
	return 0;
}

void Collision_Detection(sf::FloatRect player_Bounds,sf::FloatRect Other_Bounds[row][colm], char arr[row][colm], bool &can_move , bool &won)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < colm; j++) {

			if (player_Bounds.intersects(Other_Bounds[i][j]) && (arr[i][j] == 'q' || arr[i][j] == 'w'))
			{
				can_move = false;
				break;
				//std::cout << "colission" << std::endl;
			}
			else if (player_Bounds.intersects(Other_Bounds[i][j]) && arr[i][j] == 't')
			{
				won = true;
			}
			else
			{
				can_move = true;
			}
		}

		if (!can_move) {
			break;
		}

	}
}