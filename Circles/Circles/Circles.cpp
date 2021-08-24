// Circles.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<SFML/Graphics.hpp>
#include<thread>
using namespace sf;

CircleShape create()
{
	std::shared_ptr<CircleShape> circle = std::make_shared<CircleShape>(20.0f);
	(*circle.get()).setFillColor(Color::Green);
	(*circle.get()).setPosition(rand() % 900, rand() % 400);
	return *circle.get();
}
int main()
{
	RenderWindow window(VideoMode(1000, 500), "Circles");
	srand(time(0));
	const int SIZE = 10;
	auto arr = new CircleShape[SIZE];
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = create();
	}
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		for (int i = 0; i < count; i++)
		{
			window.draw(arr[i]);
		}
		window.display();
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
		if (count < SIZE)
		{
			count++;
		}
	}
}
