#include "Player.h"
#include <iostream>
Player::Player()
{
}
Player::~Player()
{
}
void Player::move()
{
	m_playerSprite.setPosition(m_playerSprite.getPosition().x + m_speed, m_playerSprite.getPosition().y);

}
void Player::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Up == t_event.key.code)
	{
		if (m_speed <= MAX_SPEED)
		{
			m_speed +=0.1;
		}
	}
	if (sf::Keyboard::Down == t_event.key.code)
	{
		if (m_speed >= 1)
		{
			m_speed -=0.1;
		}
	}
}
void Player::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{

	move();

	if (m_playerSprite.getPosition().y > t_window.getPosition().y + m_playerSprite.getGlobalBounds().height)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x, -m_playerSprite.getGlobalBounds().height);
	}


	if (m_playerSprite.getPosition().y < 0 - m_playerSprite.getGlobalBounds().height)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x, t_window.getPosition().y + m_playerSprite.getGlobalBounds().height);
	}

	if (m_playerSprite.getPosition().x > t_window.getPosition().x + m_playerSprite.getGlobalBounds().width)
	{
		m_playerSprite.setPosition(-m_playerSprite.getGlobalBounds().width, m_playerSprite.getPosition().y);
	}


	if (m_playerSprite.getPosition().x < 0 - m_playerSprite.getGlobalBounds().width)
	{
		m_playerSprite.setPosition(t_window.getPosition().x + m_playerSprite.getGlobalBounds().width, m_playerSprite.getPosition().y );
	}
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_playerSprite);
}

void Player::setupSprite(sf::Vector2f c)
{
	if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\player.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setScale(0.5f, 0.5f);
	m_playerSprite.setOrigin(m_playerSprite.getGlobalBounds().width / 2, m_playerSprite.getGlobalBounds().height / 2);
	m_playerSprite.setPosition(c);
}

