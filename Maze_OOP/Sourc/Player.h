#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player {

public:

    Player();
    Player(float speed);
    sf::Vector2f player_Direction;

    void move(float deltaTime);
    void update_Animations();
    void handleInput();
    void draw(sf::RenderWindow& window);
    void Update_Bounds();
    void Player_Animations();
    sf::FloatRect get_Bounds();
    sf::Vector2f get_Player_Position();

private:
    sf::IntRect current_Animation_Frame;
    sf::Sprite player_Sprite;
    sf::Texture player_Texture;
    sf::Vector2f player_Position , player_StartPosition , player_NextPosition;
    sf::FloatRect current_player_Bounds , new_Player_Bounds;
    float speed = 200 , position_Amount = 3;

};
