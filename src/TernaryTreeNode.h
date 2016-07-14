#ifndef TERNARYTREENODE_H_
#define TERNARYTREENODE_H_

#include "SFML/Graphics.hpp"

class TernaryTreeNode {
private:
	sf::Vertex* NewLine(float xp, float yp, float xc, float yc);
	void CreateLines();
public:
	// Used for root node
	TernaryTreeNode(int lvl);

	// Used for other nodes
	TernaryTreeNode(TreeNode* parent, int lvl);

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
