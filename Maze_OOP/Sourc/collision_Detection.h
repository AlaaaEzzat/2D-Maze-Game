#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Collision
{
public:
	bool colision = false;

	void check_Collision(sf::FloatRect player_bounds , sf::FloatRect other_bounds[21][21], char arr[21][21]);
private:

};