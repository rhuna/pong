#pragma once
#ifndef BAT_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Bat {
public:

	Bat(float startX, float startY);

	sf::FloatRect getPosition();
	sf::RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(sf::Time dt);

private:

	sf::Vector2f m_Position;

	//a rectangleshap object
	sf::RectangleShape m_Shape;
		
	float m_speed = 1000.0f;

	bool m_MovingRight = false;
	bool m_MovingLeft = false;


};

#endif // !BAT_H




