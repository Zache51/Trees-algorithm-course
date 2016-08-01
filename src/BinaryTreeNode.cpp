#include "BinaryTreeNode.h"

void BinaryTreeNode::CreateLines()
{
	float xOffset = body.getSize().x / 2;
	float yOffset = body.getSize().y / 2;

	float x = body.getPosition().x + xOffset;
	float y = body.getPosition().y + yOffset;

	float xl = left->body.getPosition().x + xOffset;
	float yl = left->body.getPosition().y + yOffset;

	leftLine = NewLine(x, y, xl, yl);

	float xr = right->body.getPosition().x + xOffset;
	float yr = right->body.getPosition().y + yOffset;

	rightLine = NewLine(x, y, xr, yr);
}

// Used for root node
BinaryTreeNode::BinaryTreeNode(int lvl)
{
	body = sf::RectangleShape(sf::Vector2f(30.0f, 30.0f));
	body.setPosition({ 0.0f, 0.0f });
	body.setFillColor(sf::Color::Cyan);
	body.setOutlineColor(sf::Color::Black);
	body.setOutlineThickness(1.0f);

	parent = nullptr;
	left = nullptr;
	right = nullptr;
	leftLine = nullptr;
	rightLine = nullptr;
	if (lvl != 0)
	{
		left = new BinaryTreeNode(this, lvl - 1);
		right = new BinaryTreeNode(this, lvl - 1);
		CreateLines();
	}
}

// Used for other nodes
BinaryTreeNode::BinaryTreeNode(BinaryTreeNode* parent, int lvl)
{
	float xOffset = 5.0f;
	float yOffset = 15.0f;

	body = sf::RectangleShape(sf::Vector2f(30.0f, 30.0f));
	body.setFillColor(sf::Color::Cyan);
	body.setOutlineColor(sf::Color::Black);
	body.setOutlineThickness(1.0f);

	this->parent = parent;
	float y = parent->body.getPosition().y - (body.getSize().y * 5) - yOffset;
	float x = 0;
	if (parent->left == nullptr)
	{
		x = parent->body.getPosition().x - 15.0f;
		x -= 30.0f * (std::pow(2, lvl) - 1) + xOffset;
	}
	else if (parent->right == nullptr)
	{
		x = parent->body.getPosition().x + 15.0f;
		x += 30.0f * (std::pow(2, lvl) - 1) + xOffset;
	}
	body.setPosition({ x, y });

	left = nullptr;
	right = nullptr;
	if (lvl != 0)
	{
		left = new BinaryTreeNode(this, lvl - 1);
		right = new BinaryTreeNode(this, lvl - 1);
		CreateLines();
	}
}

BinaryTreeNode::~BinaryTreeNode()
{
	if (left != nullptr)
	{
		delete left;
		delete leftLine;
	}
	if (right != nullptr)
	{
		delete right;
		delete rightLine;
	}
}
