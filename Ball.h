#pragma once
#ifndef BALL_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bat.h"


class Ball{
public:
	Ball(float startX, float startY);
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();
	float getXVelocity();
	void reboundSides();
	void reboundBatOrTop();
	void reboundBottom();
	void update(sf::Time dt);


private:
	sf::Vector2f m_Position;
	sf::RectangleShape m_Shape;

	float m_Speed = 300.0f;
	float m_DirectionX = 0.2f;
	float m_DirectionY = 0.2f;


};

#endif // !BALL_H



