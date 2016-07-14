/*
 * TernaryTreeNode.cpp
 *
 *  Created on: 14 jul 2016
 *      Author: zacharias
 */

#include "TernaryTreeNode.h"

sf::Vertex* TernaryTreeNode::NewLine(float xp, float yp, float xc, float yc)
{
	sf::Vertex* line = new sf::Vertex[2];
	line[0] = sf::Vertex(sf::Vector2f(xp, yp));
	line[1] = sf::Vertex(sf::Vector2f(xc, yc));
	return line;
}

void TernaryTreeNode::CreateLines()
{
	float xOffset = body.getSize().x / 2;
	float yOffset = body.getSize().y / 2;

	float x = body.getPosition().x + xOffset;
	float y = body.getPosition().y + yOffset;

	float xm = middle->body.getPosition().x + xOffset;
	float ym = middle->body.getPosition().y + yOffset;

	middleLine = NewLine(x, y, xm, ym);

	float xl = left->body.getPosition().x + xOffset;
	float yl = left->body.getPosition().y + yOffset;

	leftLine = NewLine(x, y, xl, yl);

	float xr = right->body.getPosition().x + xOffset;
	float yr = right->body.getPosition().y + yOffset;

	rightLine = NewLine(x, y, xr, yr);
}

TernaryTreeNode::TernaryTreeNode(int lvl)
{
	body = sf::RectangleShape(sf::Vector2f(30.0f, 30.0f));
	body.setPosition({ 0.0f, 0.0f });
	body.setFillColor(sf::Color::Cyan);
	body.setOutlineColor(sf::Color::Black);
	body.setOutlineThickness(1.0f);

	parent 		= nullptr;
	middle 		= nullptr,
	left 		= nullptr;
	right 		= nullptr;
	middleLine 	= nullptr;
	leftLine 	= nullptr;
	rightLine 	= nullptr;

	if (lvl != 0)
	{
		middle 	= new TernaryTreeNode(this, lvl - 1);
		left 	= new TernaryTreeNode(this, lvl - 1);
		right 	= new TernaryTreeNode(this, lvl - 1);
		CreateLines();
	}
}

TernaryTreeNode::TernaryTreeNode(TreeNode* parent, int lvl)
{
//	float xOffset = 5.0f;
//	float yOffset = 15.0f;

	body = sf::RectangleShape(sf::Vector2f(30.0f, 30.0f));
	body.setFillColor(sf::Color::Cyan);
	body.setOutlineColor(sf::Color::Black);
	body.setOutlineThickness(1.0f);
//
//	this->parent = parent;
//	float y = parent->body.getPosition().y + (body.getSize().y * 5) + yOffset;
//	float x = 0;
//	if (parent->left == nullptr)
//	{
//		x = parent->body.getPosition().x - 15.0f;
//		x -= 30.0f * (std::pow(2, lvl) - 1) + xOffset;
//	}
//	else if (parent->right == nullptr)
//	{
//		x = parent->body.getPosition().x + 15.0f;
//		x += 30.0f * (std::pow(2, lvl) - 1) + xOffset;
//	}
//	body.setPosition({ x, y });

	middle 	= nullptr;
	left 	= nullptr;
	right 	= nullptr;
	if (lvl != 0)
	{
		middle 	= new TernaryTreeNode(this, lvl - 1);
		left 	= new TernaryTreeNode(this, lvl - 1);
		right 	= new TernaryTreeNode(this, lvl - 1);
		CreateLines();
	}
}

TernaryTreeNode::~TernaryTreeNode() {
	if (middle != nullptr)
	{
		delete middle;
		delete middleLine;
	}
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

