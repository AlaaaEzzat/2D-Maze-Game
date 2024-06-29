#include "collision_Detection.h"

void  Collision::check_Collision(sf::FloatRect player_bounds, sf::FloatRect other_bounds[21][21], char arr[21][21]) {

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {

			if (player_bounds.intersects(other_bounds[i][j]) && (arr[i][j] == 'q' || arr[i][j] == 'w')) 
			{
				//move = this->colision;

				//std::cout << "colission" << std::endl;
			}										  
			else if(player_bounds.intersects(other_bounds[i][j]) && arr[i][j] == 't')
			{
				//std::cout << "colission with Treasure" << std::endl;

			}
			else{

				//move = this->colision;

			}

		}
	}
}