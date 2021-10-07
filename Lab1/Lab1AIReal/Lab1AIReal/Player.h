#pragma once

#include <SFML/Graphics.hpp>
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
private:





	sf::Texture m_playerTexture; // texture used for sfml logo
	sf::Sprite m_playerSprite; // sprite used for sfml logom_
	float m_speed = 2.0F;
	const float MAX_SPEED = 12;

};
