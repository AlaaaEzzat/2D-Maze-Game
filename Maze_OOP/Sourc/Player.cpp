#include "Player.h"

Player::Player() {

}

Player::Player(float spd) {

	this->speed = spd;
	current_Animation_Frame.height = 32;
	current_Animation_Frame.width = 32;

	player_Texture.loadFromFile("Player/Character.png");
	player_Sprite.setTextureRect(current_Animation_Frame);
	player_Sprite.setTexture(player_Texture);
	player_Sprite.scale(2, 2);

	new_Player_Bounds.height = 2.3;
	new_Player_Bounds.width = 3;
	new_Player_Bounds.left = 21;
	new_Player_Bounds.top = 19;

}


void Player::handleInput() {

	int horizontal = 0;
	int vertical = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && vertical == 0)
	{
		horizontal = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && vertical == 0)
	{
		horizontal = -1;
	}
	else
	{
		horizontal = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && horizontal == 0)
	{
		vertical = -1;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && horizontal == 0)
	{
		vertical = 1;

	}
	else
	{
		vertical = 0;
	}


	//Update the player direction based on the input
	player_Direction.x = horizontal;
	player_Direction.y = vertical;
}

void Player::Update_Bounds() {

	this->current_player_Bounds = player_Sprite.getGlobalBounds();

	current_player_Bounds.width = current_player_Bounds.width / new_Player_Bounds.width;
	current_player_Bounds.height = current_player_Bounds.height / new_Player_Bounds.height;
	current_player_Bounds.left += new_Player_Bounds.left + player_Direction.x * position_Amount;
	current_player_Bounds.top += new_Player_Bounds.top + player_Direction.y * position_Amount;
}

sf::FloatRect Player::get_Bounds() {
	return current_player_Bounds;
}

void Player::Player_Animations() 
{
}

void Player::update_Animations() {

}
void Player::move(float deltaTime ) {

	player_Position += deltaTime * speed * player_Direction;

	player_Sprite.setPosition(player_Position);

}

void Player::draw(sf::RenderWindow& window) 
{
	window.draw(player_Sprite);
}

sf::Vector2f Player::get_Player_Position() {

	return this->player_Position;
}