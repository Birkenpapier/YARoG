#pragma once

#include <memory>
#include <SFML/Graphics.hpp>


struct Conf
{
	const static sf::Color MARKER_COLOR;
	const static uint32_t MAX_MARKERS_PER_CELL;
	static uint32_t WIN_WIDTH;
	static uint32_t WIN_HEIGHT;
	static std::shared_ptr<sf::Texture> MARKER_TEXTURE;

	static void loadTextures()
	{
		Conf::MARKER_TEXTURE = std::make_shared<sf::Texture>();
		Conf::MARKER_TEXTURE->loadFromFile("ressources/circle.png");
		Conf::MARKER_TEXTURE->setSmooth(true);
	}

	static void freeTextures()
	{
		Conf::MARKER_TEXTURE = nullptr;
	}
};
