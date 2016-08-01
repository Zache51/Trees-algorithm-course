#include "TernaryTree.h"

TernaryTree::TernaryTree()
{
	root = new TernaryTreeNode(0);
}

TernaryTree::TernaryTree(int lvl)
{
	root = new TernaryTreeNode(lvl);
}

TernaryTree::~TernaryTree()
{
	delete root;
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

void TernaryTree::Draw(sf::RenderWindow* window)
{
	if (root != nullptr)
	{
		Draw(window, root);
	}
}
