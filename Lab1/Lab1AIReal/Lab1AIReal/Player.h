#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include<math.h>

class Player
{

public:
	Player();
	~Player();
	/// <summary>
	/// main method for game
	/// </summary>

	void setupSprite(sf::Vector2f t_pos);
	void move();

	void processKeys(sf::Event t_event);

	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window);
	void render(sf::RenderWindow& t_window);

	void rotation();
private:





	sf::Texture m_playerTexture; // texture used for sfml logo
	sf::Sprite m_playerSprite; // sprite used for sfml logom_
	
	 float m_speed = 5;
	const float MAX_SPEED = 10;
	float m_rotation = 0;
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
};
