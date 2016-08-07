#include "TernaryTree.h"
#include <iostream>
TernaryTree::TernaryTree()
{
	creationCompleted = false;
	creationOngoing = false;
	drawOngoing = false;
	drawCompleted = false;

	counter = 0;

	size = 1;
	treeNodes = new TernaryTreeNode*[size];
	treeNodes[0] = new TernaryTreeNode();
	treeNodes[0]->body = sf::RectangleShape(sf::Vector2f(30.0f, 30.0f));

	lvl = 0;
}

TernaryTree::TernaryTree(int lvl)
{
	creationCompleted = false;
	creationOngoing = false;
	drawOngoing = false;
	drawCompleted = false;

	counter = 0;

	size = 1;
	for (int i = 1; i < lvl + 1; i++)
	{
		size += std::pow(3, i);
	}
	treeNodes = new TernaryTreeNode*[size];

	for(int i = 0; i < size + 1; i++)
	{
		treeNodes[i] = new TernaryTreeNode();
	}

	this->lvl = lvl;


}

TernaryTree::~TernaryTree()
{
	//delete root;

	std::cout << "Destructor called" << std::endl;

	for (int i = 0; i < size; i++)
	{
		delete treeNodes[i];
		treeNodes[i] = nullptr;
	}
	delete[] treeNodes;
	treeNodes = nullptr;
}

void TernaryTree::CreateNode(TernaryTreeNode* parent, int lvl)
{
	TernaryTreeNode* current = treeNodes[counter];
	counter++;

	float xOffset = 15.0f;
	float yOffset = 15.0f * std::pow(lvl, 2);

	// Set correct position for the node
	float y = parent->body.getPosition().y + (current->body.getSize().y * 5) + yOffset;
	float x = parent->body.getPosition().x;

	if (parent->middle == nullptr)
	{
		parent->middle = current;
	}
	else if (parent->left == nullptr)
	{
		parent->left = current;
		x -= 15.0f;
		x -= 35.0f * (std::pow(3, lvl) - 1) + xOffset;
	}
	else if (parent->right == nullptr)
	{
		parent->right = current;
		x += 15.0f;
		x += 35.0f * (std::pow(3, lvl) - 1) + xOffset;
	}
	current->body.setPosition({ x, y });

//	if (counter % 1 == 0)
//	{
//		sf::sleep(sf::microseconds(10));
//	}

	if (lvl != 0)
	{
		CreateNode(current, lvl - 1);
		CreateNode(current, lvl - 1);
		CreateNode(current, lvl - 1);

		current->CreateLines();
	}
}

void TernaryTree::Draw(sf::RenderWindow* window, TernaryTreeNode* toDraw)
{
	if (toDraw != nullptr)
	{
		if (toDraw->middleLine != nullptr)
		{
			window->draw(toDraw->middleLine, 2, sf::Lines);
		}
		if (toDraw->leftLine != nullptr)
		{
			window->draw(toDraw->leftLine, 2, sf::Lines);
		}
		if (toDraw->rightLine != nullptr)
		{
			window->draw(toDraw->rightLine, 2, sf::Lines);
		}

		window->draw(toDraw->body);
		Draw(window, toDraw->middle);
		Draw(window, toDraw->left);
		Draw(window, toDraw->right);
	}
}

void TernaryTree::CreateNodes()
{
	TernaryTreeNode* root = treeNodes[0];
	counter++;
	treeNodes[0]->body = sf::RectangleShape(sf::Vector2f(30.0f, 30.0f));
	treeNodes[0]->body.setPosition(0, -15.0f * pow(lvl, 2));

	if (lvl != 0)
	{
		sf::Clock clock = sf::Clock();
		creationOngoing = true;

		CreateNode(root, lvl - 1);
		CreateNode(root, lvl - 1);
		CreateNode(root, lvl - 1);

		root->CreateLines();

		creationOngoing = false;
		creationCompleted = true;

		timeTaken = clock.getElapsedTime();
	}
}

void TernaryTree::Draw(sf::RenderWindow* window)
{
//	if (root != nullptr)
//	{
//		Draw(window, root);
//	}
	if (size > 0)
	{
		Draw(window, treeNodes[0]);
	}
}

void TernaryTree::Draw2(sf::RenderWindow* window)
{
	if (size > 0)
	{
		drawCompleted = false;
		int max = counter - 1;
		for(int i = 0; i < max; i++)
		{
			window->draw(treeNodes[i]->body);
			if (treeNodes[i]->middleLine != nullptr)
			{
				window->draw(treeNodes[i]->middleLine, 2, sf::Lines);
			}
			if (treeNodes[i]->leftLine != nullptr)
			{
				window->draw(treeNodes[i]->leftLine, 2, sf::Lines);
			}
			if (treeNodes[i]->rightLine != nullptr)
			{
				window->draw(treeNodes[i]->rightLine, 2, sf::Lines);
			}
		}
		beginDraw = max;

		if (counter == size) drawCompleted = true;
	}
}
