#ifndef TERNARYTREE_H_
#define TERNARYTREE_H_

#include <SFML/Graphics.hpp>
#include "TernaryTreeNode.h"

class TernaryTree
{
private:
	int lvl;
	int size;
	int counter;
	TernaryTreeNode* treeNodes;

	float yStart;

	int beginDraw = 0;

	sf::Time timeTaken;

	bool creationOngoing;
	bool creationCompleted;
	bool drawOngoing;
	bool drawCompleted;

	// Recursive function used by CreateNodes
	void CreateNode(TernaryTreeNode* parent, int lvl);

	// Recursive and dynamic function used by CreateNodes2
	void CreateNode2(TernaryTreeNode* parent, int lvl);

	// Recursive private function of Draw
	void Draw(sf::RenderWindow* window, TernaryTreeNode* toDraw);

public:
	TernaryTree();
	TernaryTree(int lvl, float yStart);
	virtual ~TernaryTree();

	// Creates the tree structure recursively
	void CreateNodes();

	// Creates the tree structure recursively with dynamic programing
	void CreateNodes2();

	// Draws the tree recursively
	void Draw(sf::RenderWindow* window);

	// Draws the tree sequentially
	void Draw2(sf::RenderWindow* window);

	sf::Time getTimeTaken() const {
		return timeTaken;
	}

	bool isCreationCompleted() const {
		return creationCompleted;
	}

	bool isDrawCompleted() const {
		return drawCompleted;
	}

	bool isCreationOngoing() const {
		return creationOngoing;
	}

	bool isDrawOngoing() const {
		return drawOngoing;
	}
};

#endif
