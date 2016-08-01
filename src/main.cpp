#include <SFML/Graphics.hpp>
#include "BinaryTree.h"
#include "TernaryTree.h"

#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 640), "Ternary Tree comparison");

	BinaryTree bt = BinaryTree(5);
	TernaryTree tt = TernaryTree(5);

	// create a view with the rectangular area of the 2D world to show
	sf::View view = window.getDefaultView();

	sf::Vector2i worldPos = (sf::Vector2i)view.getCenter();
	sf::Vector2i mousePos = {0, 0};

	bool drag = false;

	float zoom = 1.0f;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (event.type == sf::Event::MouseButtonPressed)
				{
					drag = true;
					mousePos = sf::Mouse::getPosition();
					mousePos -= window.getPosition();
				}
				else if (event.type == sf::Event::MouseButtonReleased)
				{
					drag = false;
				}
			}

			if (drag && sf::Event::MouseMoved)
			{
				sf::Vector2i deltaPos = mousePos - (sf::Mouse::getPosition() - window.getPosition());

				deltaPos.x *= zoom;
				deltaPos.y *= zoom;

				worldPos += deltaPos;

				view.setCenter((sf::Vector2f)(worldPos));
				window.setView(view);

				mousePos = sf::Mouse::getPosition();
				mousePos -= window.getPosition();
			}

			if (event.type == sf::Event::MouseWheelScrolled)
			{
				if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
				{
					if (event.mouseWheelScroll.delta > 0)
					{
						zoom -= 0.5f;
						view.setSize(window.getDefaultView().getSize());
						view.zoom(zoom);
					}
					else if (event.mouseWheelScroll.delta < 0)
					{
						zoom += 0.5f;
						view.setSize(window.getDefaultView().getSize());
						view.zoom(zoom);
					}
					window.setView(view);
				}
				std::cout << "X:" << view.getSize().x << " Y:" << view.getSize().y << std::endl;
			}
		}

		window.clear();
		
		bt.Draw(&window);
		tt.Draw(&window);

		window.display();
	}

	return 0;
}
