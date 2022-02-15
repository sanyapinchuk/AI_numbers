#define _CRT_SECURE_NO_WARNINGS
#include "NumberImage.h"
#include <string>

NumberImage::NumberImage()
{

}
NumberImage::~NumberImage()
{

}

void NumberImage::LoadPicture(int current, sf::RenderWindow& window)
{
	filePictures = fopen("../images/train-images.idx3-ubyte", "rb");

	if (!(fseek(filePictures, 16 + current*28*28, SEEK_SET)))
	{
		unsigned char sim;
		for (int i = 0; i < 28; i++)
		{
			for (int j = 0; j < 28; j++)
			{
				if (!feof(filePictures))
				{
					fscanf(filePictures, "%c", &sim);
					window.draw(AddPixel({ (float)j,(float)i }, (float)sim / 255));
					
				}
					
				else
					std::cout << "ENDDDDDDDDDDDDDDDDDDDDDDDDD" << std::endl;
			}
		}
		//std::cout << fgetc(fileLabels) << " ";
	}
	else
		std::cout << "FSEEEEK" << std::endl;
	fclose(filePictures);

}

void NumberImage::LoadLabel(int current, sf::RenderWindow& window)
{

	fileLabels = fopen("../images/train-labels.idx1-ubyte", "rb");
	sf::Text text;
	sf::Font font;
	font.loadFromFile("../fonts/NotoSansJP-Regular.otf");
	text.setFont(font);
	text.setCharacterSize(50);
	text.setPosition({ 200,30 });
	text.setFillColor(sf::Color::White);
	

	if (!(fseek(fileLabels, 8 + current, SEEK_SET)))
	{
		std::string str= std::to_string(fgetc(fileLabels));
		text.setString(str);
		window.draw(text);
	}
	else
		std::cout << "FSEEEEK" << std::endl;

	fclose(fileLabels);
}

sf::RectangleShape NumberImage::AddPixel(sf::Vector2f position, float color)
{
	sf::RectangleShape pixel;
	pixel.setSize({ 1.0f,1.0f });
	pixel.setPosition(position);
	pixel.setFillColor({ (unsigned char)(255 * color),(unsigned char)(255 * color),(unsigned char)(255 * color) });
	return pixel;
}

void NumberImage::ReadPicture()
{
	filePictures = fopen("../images/train-images.idx3-ubyte", "rb");

	

	fclose(filePictures);
}