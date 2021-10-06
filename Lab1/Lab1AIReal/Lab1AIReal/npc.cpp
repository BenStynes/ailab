#include "npc.h"
#include <iostream>
npc::npc()
{
}
npc::~npc()
{
}
void npc::move()
{
	m_playerSprite.setPosition(m_playerSprite.getPosition().x, m_playerSprite.getPosition().y + 10);
	
}

void npc::update(sf::Time t_deltaTime,sf::RenderWindow& t_window)
{

	move();

	if (m_playerSprite.getPosition().y > t_window.getPosition().y +m_playerSprite.getGlobalBounds().height)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x, -m_playerSprite.getGlobalBounds().height);
	}
}

void npc::render(sf::RenderWindow &t_window)
{
	t_window.draw(m_playerSprite);
}

void npc::setupSprite(sf::Vector2f c)
{
	if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\player.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setScale(0.5f, 0.5f);
	m_playerSprite.setOrigin(m_playerSprite.getGlobalBounds().width/2 , m_playerSprite.getGlobalBounds().height/2 );
	m_playerSprite.setPosition(c);
}
