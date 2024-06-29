#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Camera
{
public:

	Camera();
	Camera(sf::RenderWindow& window);
	void check_Camera_Limits(sf::Vector2f playerposition);
	void move_Camera(sf::RenderWindow& window);


private:
	sf::View view;
	sf::Vector2f camera_Limit;
	float left_Limit = 360, right_Limit = 800, up_Limit = 390, down_Limit = 980;
};