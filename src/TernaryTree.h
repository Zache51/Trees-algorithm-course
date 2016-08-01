#ifndef TERNARYTREE_H_
#define TERNARYTREE_H_

#include <SFML/Graphics.hpp>
#include "TernaryTreeNode.h"

class TernaryTree
{
private:
	TernaryTreeNode* root;

	// Recursive private function of Draw
	void Draw(sf::RenderWindow* window, TernaryTreeNode* toDraw);

public:
	TernaryTree();
	TernaryTree(int lvl);
	virtual ~TernaryTree();

	// Draws the tree
	void Draw(sf::RenderWindow* window);
};

#endif
