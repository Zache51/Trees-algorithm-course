#include <SFML/Graphics.hpp>
#include "BinaryTree.h"
#include "TernaryTree.h"

#include <iostream>

TernaryTree* ttr = new TernaryTree(12);
TernaryTree* ttr2 = new TernaryTree(12);

bool render = false;
bool drawCompleted = false;
bool creationOngoing = false;

sf::RenderWindow window(sf::VideoMode(1920, 640), "Ternary Tree comparison");

int main()
{
	// create a view with the rectangular area of the 2D world to show
	sf::View view = window.getDefaultView();

	sf::Vector2i worldPos = (sf::Vector2i)view.getCenter();
	sf::Vector2i mousePos = {0, 0};

	bool drag = false;

	float zoom = 30.0f;
	view.setSize(window.getDefaultView().getSize());
	view.zoom(zoom);
	window.setView(view);

	int counter = 0;

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
						zoom -= 5.0f;
						view.setSize(window.getDefaultView().getSize());
						view.zoom(zoom);
					}
					else if (event.mouseWheelScroll.delta < 0)
					{
						zoom += 5.0f;
						view.setSize(window.getDefaultView().getSize());
						view.zoom(zoom);
					}
					window.setView(view);
				}
			}
		}

		window.clear();
		if (counter == 0)
		{
			window.display();

			std::cout << "Test starts in 3 seconds" << std::endl;
			sf::sleep(sf::seconds(3));
		}
		else if (counter == 1)
		{
			// Ternary tree recursive code

			// Instancing and creating
			ttr->CreateNodes();
			std::cout << "Ternary Tree: " << ttr->getTimeTaken().asMilliseconds() << " milliseconds" << std::endl;

			// Graphics stuff
			std::cout << "Drawing tree" << std::endl;
			ttr->Draw2(&window);
			std::cout << "Drawing of tree completed" << std::endl;
			window.display();

			// Destroy tree
			delete ttr;
			ttr = nullptr;
		}
		else if (counter == 2)
		{
			// Separator
			std::cout << "Wait 3 seconds for next tree" << std::endl;
			sf::sleep((sf::seconds(3)));
			window.display();
		}
		else if (counter == 3)
		{
			// Ternary tree recursive2 code

			// Instancing and creating
			ttr2->CreateNodes();
			std::cout << "Ternary Tree: " << ttr2->getTimeTaken().asMilliseconds() << " milliseconds" << std::endl;

			// Graphics stuff
			std::cout << "Drawing tree" << std::endl;
			ttr2->Draw2(&window);
			std::cout << "Drawing of tree completed" << std::endl;
			window.display();

			std::cout << "Test completed" << std::endl;
		}
		else
		{
			// Graphics stuff
			ttr2->Draw(&window);
			window.display();
		}

		counter++;
	}

	// Destroy tree
	delete ttr2;
	ttr2 = nullptr;

	return 0;
}
