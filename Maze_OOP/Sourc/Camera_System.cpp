#include "Camera_System.h"


Camera::Camera() {

}

Camera::Camera(sf::RenderWindow& window) {

	this->view = window.getDefaultView();

}

void Camera::check_Camera_Limits(sf::Vector2f playerposition)
{
	if (((view.getCenter().x < right_Limit && view.getCenter().x > left_Limit)))
	{
		if ((playerposition.x < 710 && playerposition.x > 400))
		{

			view.setCenter(sf::Vector2f(playerposition.x, view.getCenter().y));
		}
	}

	if ((view.getCenter().y < down_Limit && view.getCenter().y > up_Limit)) {

		if ((playerposition.y > 400 && playerposition.y < 960))
		{

			view.setCenter(sf::Vector2f(view.getCenter().x, playerposition.y));
		}
	}

}

void Camera::move_Camera(sf::RenderWindow& window) {

	window.setView(view);
	//if (view.getRotation() < 180) {
	//	view.rotate(0.02f);

	//}
}