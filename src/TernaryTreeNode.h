#ifndef TERNARYTREENODE_H_
#define TERNARYTREENODE_H_

#include "TreeNode.h"
#include "SFML/Graphics.hpp"

class TernaryTreeNode : TreeNode
{
private:
	void CreateLines();
public:
	// Used for root node
	TernaryTreeNode(int lvl);

	// Used for other nodes
	TernaryTreeNode(TernaryTreeNode* parent, int lvl);

	virtual ~TernaryTreeNode();

	TernaryTreeNode* parent;
	TernaryTreeNode* middle;
	TernaryTreeNode* left;
	TernaryTreeNode* right;

	sf::RectangleShape body;
	sf::Vertex* middleLine;
	sf::Vertex* leftLine;
	sf::Vertex* rightLine;

};

#endif
