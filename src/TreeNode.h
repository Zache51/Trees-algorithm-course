#pragma once

#include "SFML/Graphics.hpp"

class TreeNode
{
private:
	void CreateLines() {
		float xOffset = body.getSize().x / 2;
		float yOffset = body.getSize().y / 2;
		float x = body.getPosition().x + xOffset;
		float y = body.getPosition().y + yOffset;
		float xl = left->body.getPosition().x + xOffset;
		float yl = left->body.getPosition().y + yOffset;
		leftLine = new sf::Vertex[2];
		leftLine[0] = sf::Vertex(sf::Vector2f(x, y));
		leftLine[1] = sf::Vertex(sf::Vector2f(xl, yl));
		float xr = right->body.getPosition().x + xOffset;
		float yr = right->body.getPosition().y + yOffset;
		rightLine = new sf::Vertex[2];
		rightLine[0] = sf::Vertex(sf::Vector2f(x, y));
		rightLine[1] = sf::Vertex(sf::Vector2f(xr, yr));
	}
public:
	// Used for root node
	TreeNode(int lvl);

	// Used for other nodes
	TreeNode(TreeNode* parent, int lvl);

	~TreeNode();

	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;

	sf::RectangleShape body;
	sf::Vertex* leftLine;
	sf::Vertex* rightLine;
};
