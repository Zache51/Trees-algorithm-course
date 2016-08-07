#include "TernaryTreeNode.h"

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

TernaryTreeNode::TernaryTreeNode()
{
	body = sf::RectangleShape(sf::Vector2f(30.0f, 30.0f));
	body.setFillColor(sf::Color::Cyan);
	body.setOutlineColor(sf::Color::Black);
	body.setOutlineThickness(1.0f);

	middle 	= nullptr;
	left 	= nullptr;
	right 	= nullptr;

	middleLine = nullptr;
	rightLine = nullptr;
	leftLine = nullptr;
}

TernaryTreeNode::~TernaryTreeNode()
{
	delete middleLine;
	middleLine = nullptr;

	delete rightLine;
	rightLine = nullptr;

	delete leftLine;
	leftLine = nullptr;
}
