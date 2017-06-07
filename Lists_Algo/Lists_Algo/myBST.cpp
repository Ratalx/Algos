#include "myBST.h"


void InsertBST(BSTNode *& root, int x)
{
	BSTNode *p, *w;
	w = new BSTNode;
	w->left = w->right = NULL;
	w->val = x;
	p = root;
	if (!p)
		root = w;
	else
		while (true)              
			if (x < p->val)         
			{                      
				if (!p->left)         
				{
					p->left = w;      
					break;             
				}
				else p = p->left;
			}
			else
			{
				if (!p->right)        
				{
					p->right = w;      
					break;             
				}
				else p = p->right;
			}

	w->parent = p;                

}
void DFSRelease(BSTNode*& root)
{
	if (root)
	{
		DFSRelease(root->left);
		DFSRelease(root->right);
		delete root;
	}
}
BSTNode * minBST(BSTNode *& root)
{
	if(root) while (root->left) root = root->left;

	return root;
}
BSTNode * nextBST(BSTNode *root)
{
	if (root == NULL)
		return NULL;
	if (root->right)
	{
		return minBST(root->right);
	}
	BSTNode * w = root->parent;
	while (w != NULL && (root == w->right))
	{
		root = w;
		w = root->parent;
	}
	return w;
}

BSTNode * predBST(BSTNode * root)
{
	BSTNode *p;
	if (root)
	{
		if (root->left) return MaxBST(root->left);
		p = root->parent;
		while (p != NULL && (root == p->right))
		{
			root = p;
			p = root->parent;
		}
	}
	return root;
}

BSTNode * MaxBST(BSTNode * root)
{
	if (root)
	{
		while (root->right)
		{
			root = root->right;
		}
	}
	return nullptr;
}
