#include "TernaryTree.h"

TernaryTree::TernaryTree()
{
	//root = new TernaryTreeNode(0);

	size = 1;
	treeNodes = new TernaryTreeNode*[size];
	treeNodes[0] = new TernaryTreeNode();
	treeNodes[0]->body = sf::RectangleShape(sf::Vector2f(30.0f, 30.0f));
}

TernaryTree::TernaryTree(int lvl)
{
	//root = new TernaryTreeNode(lvl);

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



	TernaryTreeNode* root = treeNodes[0];
	counter++;
	treeNodes[0]->body = sf::RectangleShape(sf::Vector2f(30.0f, 30.0f));

	if (lvl != 0)
	{
		// new index = last created + 1

		CreateNode(root, lvl - 1);
		CreateNode(root, lvl - 1);
		CreateNode(root, lvl - 1);

		root->CreateLines();
	}
}

TernaryTree::~TernaryTree()
{
	//delete root;

	for (int i = 0; i < size; i++)
	{
		delete treeNodes[i];
	}
	delete [] treeNodes;
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

void TernaryTree::CreateNode(TernaryTreeNode* parent, int lvl)
{
	TernaryTreeNode* current = treeNodes[counter];
	counter++;

	float xOffset = 15.0f;
	float yOffset = 15.0f;

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

	if (lvl != 0)
	{
		CreateNode(current, lvl - 1);
		CreateNode(current, lvl - 1);
		CreateNode(current, lvl - 1);

		current->CreateLines();
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
