#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <SFML/Graphics.hpp>
#include "BinaryTreeNode.h"

class BinaryTree
{
private:
	BinaryTreeNode* root;

	// Recursive private function of Draw
	void Draw(sf::RenderWindow* window, BinaryTreeNode* toDraw);

public:
	BinaryTree();
	BinaryTree(int lvl);
	~BinaryTree();

	// Draws the tree
	void Draw(sf::RenderWindow* window);
};

#endif

