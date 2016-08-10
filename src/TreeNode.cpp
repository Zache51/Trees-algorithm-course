/*
 * TreeNode.cpp
 *
 *  Created on: 30 jul 2016
 *      Author: zacharias
 */

#include "TreeNode.h"

TreeNode::TreeNode()
{
	// TODO Auto-generated constructor stub
}

TreeNode::~TreeNode()
{
	// TODO Auto-generated destructor stub
}

sf::Vertex* TreeNode::NewLine(float xp, float yp, float xc, float yc)
{
	sf::Vertex* line = new sf::Vertex[2];
	line[0] = sf::Vertex(sf::Vector2f(xp, yp));
	line[1] = sf::Vertex(sf::Vector2f(xc, yc));
	return line;
}
