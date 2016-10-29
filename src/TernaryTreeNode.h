#ifndef TERNARYTREENODE_H_
#define TERNARYTREENODE_H_

#include "TreeNode.h"
#include "SFML/Graphics.hpp"

class TernaryTreeNode : TreeNode
{
private:

public:

	TernaryTreeNode();

	~TernaryTreeNode();

	void CreateLines();
	void CreateLines(TernaryTreeNode* image, float lvlOffset);

	//int parent;
	TernaryTreeNode* middle;
	TernaryTreeNode* left;
	TernaryTreeNode* right;

	sf::RectangleShape body;
	sf::Vertex* middleLine;
	sf::Vertex* leftLine;
	sf::Vertex* rightLine;

};

#endif
