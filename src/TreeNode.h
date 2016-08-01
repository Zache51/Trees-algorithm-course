/*
 * TreeNode.h
 *
 *  Created on: 30 jul 2016
 *      Author: zacharias
 */

#ifndef TREENODE_H_
#define TREENODE_H_

#include "SFML/Graphics.hpp"

class TreeNode {
protected:
	virtual sf::Vertex* NewLine(float xp, float yp, float xc, float yc);
	virtual void CreateLines() = 0;

public:
	TreeNode();
	TreeNode(int lvl);
	virtual ~TreeNode();
};

#endif /* TREENODE_H_ */
