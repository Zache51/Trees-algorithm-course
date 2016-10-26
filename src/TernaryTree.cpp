#include "TernaryTree.h"
#include <iostream>

// Constructors and Destructor

TernaryTree::TernaryTree()
{
	yStart = 0;

	creationCompleted = false;
	creationOngoing = false;
	drawOngoing = false;
	drawCompleted = false;

	counter = 0;

	size = 1;
	treeNodes = new TernaryTreeNode[size];

	lvl = 0;
}

TernaryTree::TernaryTree(int lvl, float yStart)
{
	this->yStart = yStart;

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
	treeNodes = new TernaryTreeNode[size];

	this->lvl = lvl;


}

TernaryTree::~TernaryTree()
{
	std::cout << "Destructor called" << std::endl;
	delete[] treeNodes;
	treeNodes = nullptr;
}


// Private functions

void TernaryTree::CreateNode(TernaryTreeNode* parent, int lvl)
{
	TernaryTreeNode* current = &treeNodes[counter];
	counter++;

	//float xOffset = 15.0f;
	//float yOffset = 45.0f * std::pow(lvl, 2);

	// Set correct position for the node
	//float y = parent->body.getPosition().y + current->body.getSize().y * 5 + yOffset;
	//float x = parent->body.getPosition().x;

	if (parent->middle == nullptr)
	{
		parent->middle = current;
	}
	else if (parent->left == nullptr)
	{
		parent->left = current;
		//x -= 15.0f;
		//x -= 35.0f * (std::pow(3, lvl) - 1) + xOffset;
	}
	else if (parent->right == nullptr)
	{
		parent->right = current;
		//x += 15.0f;
		//x += 35.0f * (std::pow(3, lvl) - 1) + xOffset;
	}
	//current->body.setPosition({ x, y });

	if (lvl != 0)
	{
		CreateNode(current, lvl - 1);
		CreateNode(current, lvl - 1);
		CreateNode(current, lvl - 1);

		//current->CreateLines();
	}
}

void TernaryTree::CreateNode2(TernaryTreeNode* parent, int lvl)
{
	TernaryTreeNode* current = &treeNodes[counter];
	int ownIndex = counter++;

	//float xOffset = 15.0f;
	//float yOffset = 45.0f * std::pow(lvl, 2);

	// Set correct position for the node
	//float y = parent->body.getPosition().y + current->body.getSize().y * 5 + yOffset;
	//float x = parent->body.getPosition().x;

	//current->body.setPosition({ x, y });

	if (lvl != 0)
	{
		CreateNode2(current, lvl - 1);

		int copyAmount = 1;
		for (int i = 1; i < lvl; i++)
		{
			copyAmount += std::pow(3, i);
		}

		//int lvlOffset = 35.0f * (std::pow(3, lvl - 1) - 1) + xOffset;

		//for (int i = ownIndex + 1; i < ownIndex + copyAmount + 1; i++)
		//{
			//sf::Vector2f vec = treeNodes[i].body.getPosition();
			//x = 15.0f + lvlOffset;

			// Offset left
			//treeNodes[i + copyAmount].body.setPosition(vec.x - x, vec.y);
			//treeNodes[i + copyAmount].CreateLines(&treeNodes[i], -x);

			// Offset right
			//treeNodes[i + copyAmount * 2].body.setPosition(vec.x + x, vec.y);
			//treeNodes[i + copyAmount * 2].CreateLines(&treeNodes[i], x);
		//}

		treeNodes[ownIndex].middle = &treeNodes[ownIndex + 1];
		treeNodes[ownIndex].left = &treeNodes[ownIndex + copyAmount + 1];
		treeNodes[ownIndex].right = &treeNodes[ownIndex + copyAmount * 2 + 1];
		//treeNodes[ownIndex].CreateLines();

		counter += copyAmount * 2;
	}
}

void TernaryTree::Draw(sf::RenderWindow* window, TernaryTreeNode* toDraw)
{
	//if (toDraw != nullptr)
	//{
	//	if (toDraw->middleLine != nullptr)
	//	{
	//		window->draw(toDraw->middleLine, 2, sf::Lines);
	//	}
	//	if (toDraw->leftLine != nullptr)
	//	{
	//		window->draw(toDraw->leftLine, 2, sf::Lines);
	//	}
	//	if (toDraw->rightLine != nullptr)
	//	{
	//		window->draw(toDraw->rightLine, 2, sf::Lines);
	//	}
	//
	//	window->draw(toDraw->body);
	//	Draw(window, toDraw->middle);
	//	Draw(window, toDraw->left);
	//	Draw(window, toDraw->right);
	//}
}


// Public functions

void TernaryTree::CreateNodes()
{
	TernaryTreeNode* root = &treeNodes[0];
	counter++;

	//root->body.setPosition(0, yStart * pow(lvl, 2));

	if (lvl != 0)
	{
		sf::Clock clock = sf::Clock();
		creationOngoing = true;

		CreateNode(root, lvl - 1);
		CreateNode(root, lvl - 1);
		CreateNode(root, lvl - 1);

		//root->CreateLines();

		creationOngoing = false;
		creationCompleted = true;

		timeTaken = clock.getElapsedTime();
	}
}

void TernaryTree::CreateNodes2()
{
	TernaryTreeNode* root = &treeNodes[0];
	counter++;

	//root->body.setPosition(0, yStart * pow(lvl, 2));

	if (lvl != 0)
	{
		sf::Clock clock = sf::Clock();
		creationOngoing = true;

		float xOffset = 15.0f;
		float x;

		CreateNode2(root, lvl - 1);

		int copyAmount = (size - 1) / 3;

		//int lvlOffset = 35.0f * (std::pow(3, lvl - 1) - 1) + xOffset;

		//for (int i = 1; i < copyAmount + 1; i++)
		//{
			//sf::Vector2f vec = treeNodes[i].body.getPosition();
			//x = 15.0f + lvlOffset;

			// Offset left
			//treeNodes[i + copyAmount].body.setPosition(vec.x - x, vec.y);
			//treeNodes[i + copyAmount].CreateLines(&treeNodes[i], -x);

			// Offset right
			//treeNodes[i + copyAmount * 2].body.setPosition(vec.x + x, vec.y);
			//treeNodes[i + copyAmount * 2].CreateLines(&treeNodes[i], x);
		//}

		counter += (counter - 1) * 2;

		root->middle = &treeNodes[1];
		root->left = &treeNodes[copyAmount + 1];
		root->right = &treeNodes[copyAmount * 2 + 1];
		//root->CreateLines();

		creationOngoing = false;
		creationCompleted = true;

		timeTaken = clock.getElapsedTime();
	}
}

void TernaryTree::Draw(sf::RenderWindow* window)
{
	if (size > 0)
	{
		Draw(window, &treeNodes[0]);
	}
}

void TernaryTree::Draw2(sf::RenderWindow* window)
{
	//if (size > 0)
	//{
		//drawCompleted = false;
		//int max = counter;
		//for(int i = 0; i < max; i++)
		//{
			//if (treeNodes[i].middleLine != nullptr)
			//{
			//	window->draw(treeNodes[i].middleLine, 2, sf::Lines);
			//}
			//if (treeNodes[i].leftLine != nullptr)
			//{
			//	window->draw(treeNodes[i].leftLine, 2, sf::Lines);
			//}
			//if (treeNodes[i].rightLine != nullptr)
			//{
			//	window->draw(treeNodes[i].rightLine, 2, sf::Lines);
			//}
			//window->draw(treeNodes[i].body);
		//}
		//beginDraw = max;
//
		//if (counter == size) drawCompleted = true;
	//}
}
