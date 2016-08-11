#include <SFML/Graphics.hpp>
#include "TernaryTree.h"

#include <iostream>

void treeTest(TernaryTree* t, std::string type)
{
	if (type == "r") t->CreateNodes();
	else if (type == "dp/r") t->CreateNodes2();
	std::cout << "Ternary Tree " << type << ": " << t->getTimeTaken().asMilliseconds() << " milliseconds" << std::endl;
	delete t;
	t = nullptr;
}

void performenceTest(int lowerlvl, int upperlvl)
{
	for (int lvl = lowerlvl; lvl < upperlvl + 1; lvl++)
	{
		TernaryTree* t[8];

		for (int i = 0; i < 8; i++)
		{
			t[i] = new TernaryTree(lvl, 0);
		}

		std::cout << "Start lvl " << lvl << std::endl;

		treeTest(t[0], "r");
		treeTest(t[1], "dp/r");
		treeTest(t[2], "r");
		treeTest(t[3], "dp/r");

		std::cout << "Start lvl " << lvl << " reverse" << std::endl;
		sf::sleep(sf::seconds(0.5));

		treeTest(t[4], "dp/r");
		treeTest(t[5], "r");
		treeTest(t[6], "dp/r");
		treeTest(t[7], "r");

		std::cout << "test for lvl " << lvl << " completed" << std::endl;
		sf::sleep(sf::seconds(0.5));
	}
}

void demo(int lvl)
{
	sf::RenderWindow window(sf::VideoMode(1920, 640), "Ternary Tree comparison");

	// create a view with the rectangular area of the 2D world to show
	 sf::View view = window.getDefaultView();

	sf::Vector2i worldPos = (sf::Vector2i)view.getCenter();
	sf::Vector2i mousePos = {0, 0};

	bool drag = false;

	float zoom = 50.0f;
	view.setSize(window.getDefaultView().getSize());
	view.zoom(zoom);
	window.setView(view);

	int counter = 0;

	TernaryTree* ttr = new TernaryTree(lvl, -75.0f);
	TernaryTree* ttrdp = new TernaryTree(lvl, -75.0f);

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
						zoom -= 2.0f;
						view.setSize(window.getDefaultView().getSize());
						view.zoom(zoom);
					}
					else if (event.mouseWheelScroll.delta < 0)
					{
						zoom += 2.0f;
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
			// Ternary tree recursive dynamic programming code

			// Instancing and creating
			ttrdp->CreateNodes2();
			std::cout << "Ternary Tree: " << ttrdp->getTimeTaken().asMilliseconds() << " milliseconds" << std::endl;

			// Graphics stuff
			std::cout << "Drawing tree" << std::endl;
			ttrdp->Draw2(&window);
			std::cout << "Drawing of tree completed" << std::endl;
			window.display();

			std::cout << "Test completed" << std::endl;
		}
		else
		{
			// Graphics stuff
			ttrdp->Draw2(&window);
			window.display();
		}

		counter++;
	}

	// Destroy tree
	delete ttrdp;
	ttrdp = nullptr;
}

int main(int argc, char* argv[])
{
	for(int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;
	}

	if (argc == 3 && std::string(argv[1]) == "demo")
	{
		demo(std::atoi(argv[2]));
	}
	else if (argc == 4 && std::string(argv[1]) == "test")
	{
		performenceTest(std::atoi(argv[2]), std::atoi(argv[3]));
	}
	else
	{
		std::cerr << "Usage: " << argv[0] << "DEMO LEVEL" << std::endl;
		std::cerr << "or" << std::endl;
		std::cerr << "Usage: " << argv[0] << "TEST LOWERLEVEL UPPERLEVEL" << std::endl;
		return 1;
	}

	return 0;
}
