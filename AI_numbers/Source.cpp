#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include "NumberImage.h"
#include "AI.h"
#include <string>

void DrawResults(float a[], sf::RenderWindow& window,int result,sf::Text text);

int main()
{

	sf::RenderWindow window(sf::VideoMode(700, 500), "AI");
	NumberImage Image;
	sf::Clock clock;	
	int counter = 0;
	sf::Font font;
	font.loadFromFile("../fonts/NotoSansJP-Regular.otf");
	sf::Text text;
	
	text.setFillColor(sf::Color::White);
	text.setFont(font);
	text.setCharacterSize(24);
	text.setStyle(sf::Text::Bold);
	/////////////////////////////

	Network network;

	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/*
		if (clock.getElapsedTime().asMilliseconds() > 50)
		 {
			std::cout << counter << std::endl;
			window.clear();
			Image.LoadPicture(counter, window);
			counter++;
			clock.restart();
			window.display();
		}
		*/
		if (clock.getElapsedTime().asMilliseconds() > 500)
		{
			network.ReadPicture();
			network.MakeLayers();
			network.ShowArr();
			printf("\n");
			for (int i = 0; i < 10; i++)
			{
				printf("%4.2f ", network.result[i]);
			}
			printf("\n");
			window.clear();

			Image.LoadPicture(counter, window);
			Image.LoadLabel(counter, window);
			counter++;

			DrawResults(network.result, window, network.GetResult(),text);

			window.display();
			clock.restart();
		}
		
	}
	
	return 0;
}

void DrawResults(float a[], sf::RenderWindow &window, int result,sf::Text text)
{
	sf::RectangleShape line;
	line.setPosition({ 10,450 });
	line.setSize({ 680,10 });
	line.setFillColor(sf::Color::Red);
	window.draw(line);

	sf::RectangleShape cube;
	std::string str;
	cube.setFillColor(sf::Color::White);
	text.setCharacterSize(40);
	for (int i = 0; i < 10; i++)
	{
		
		cube.setPosition({ (float)(10 + 68 * i),450.0f });
		cube.setSize({ 60,-1* 100 * a[i] });
		window.draw(cube);
	
		str = std::to_string(i);
		text.setString(str);
		text.setPosition({ (float)(36 + 68 * i),460.0f });
		
		window.draw(text);
	
	}

	
	text.setPosition({ 10,200 });
	text.setCharacterSize(70);
	str = std::to_string(result);
	text.setString(str);




	window.draw(text);
}