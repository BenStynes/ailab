#pragma once

#include <SFML/Graphics.hpp>
class npc
{

public:
	npc();
	~npc();
	/// <summary>
	/// main method for game
	/// </summary>
	
	void setupSprite(sf::Vector2f t_pos);
	void move();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
private:

	

	
	
	sf::Texture m_playerTexture; // texture used for sfml logo
	sf::Sprite m_playerSprite; // sprite used for sfml logom_
	float m_speed = 0.9;


};

