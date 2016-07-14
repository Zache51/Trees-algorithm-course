#pragma once

#include <SFML/Graphics.hpp>
#include "TreeNode.h"

class BinaryTree
{
private:
	TreeNode* root;

	// Recursive private function of Draw
	void Draw(sf::RenderWindow* window, TreeNode* toDraw);

public:
	BinaryTree();
	BinaryTree(int lvl);
	~BinaryTree();

	// Draws the tree
	void Draw(sf::RenderWindow* window);
};

