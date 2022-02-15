#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class NumberImage
{
public:
	NumberImage();
	~NumberImage();
	sf::Sprite image;
	char* initial;
	void LoadPicture(int current, sf::RenderWindow& window);
	void LoadLabel(int current, sf::RenderWindow& window);
	void ReadPicture();
private:
	FILE* filePictures, *fileLabels;
	sf::Texture texture;
	sf::RectangleShape AddPixel(sf::Vector2f position, float color);
};

