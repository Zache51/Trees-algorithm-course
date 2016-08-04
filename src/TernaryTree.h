#ifndef TERNARYTREE_H_
#define TERNARYTREE_H_

#include <SFML/Graphics.hpp>
#include "TernaryTreeNode.h"

class TernaryTree
{
private:
	int size;
	int counter;
	TernaryTreeNode** treeNodes;

	//TernaryTreeNode* root;

	void CreateNode(TernaryTreeNode* parent, int lvl);

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
