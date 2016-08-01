#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	root = new BinaryTreeNode(0);
}

BinaryTree::BinaryTree(int lvl)
{
	root = new BinaryTreeNode(lvl);
}

BinaryTree::~BinaryTree()
{
	delete root;
}


void BinaryTree::Draw(sf::RenderWindow* window, BinaryTreeNode* toDraw)
{
	if (toDraw != nullptr)
	{
		if (toDraw->leftLine != nullptr)
		{
			window->draw(toDraw->leftLine, 2, sf::Lines);
		}
		if (toDraw->rightLine != nullptr)
		{
			window->draw(toDraw->rightLine, 2, sf::Lines);
		}

		window->draw(toDraw->body);
		Draw(window, toDraw->left);
		Draw(window, toDraw->right);
	}
}

void BinaryTree::Draw(sf::RenderWindow* window)
{
	if (root != nullptr)
	{
		Draw(window, root);
	}
}
