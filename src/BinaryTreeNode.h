#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_

#include "TreeNode.h"
#include "SFML/Graphics.hpp"

class BinaryTreeNode : TreeNode
{
private:
	void CreateLines();
public:
	// Used for root node
	BinaryTreeNode(int lvl);

	// Used for other nodes
	BinaryTreeNode(BinaryTreeNode* parent, int lvl);

	virtual ~BinaryTreeNode();

	BinaryTreeNode* parent;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	sf::RectangleShape body;
	sf::Vertex* leftLine;
	sf::Vertex* rightLine;
};

#endif
