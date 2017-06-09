#include "myBST.h"

void myInsertBST(BSTNode *& root, int x)
{
	BSTNode *w = new BSTNode;
	w->left = w->right = NULL;
	w->val = x;
	if (!root)
	{
		root = w;
	}
	else
	{
		BSTNode*p = root;
		while (1)
		{
			if (p->val > x)
			{
				if (!p->left)
				{
					p->left = w;
					break;
				}
				else p=p->left;
			}
			else
			{
				if (!p->right)
				{
					p->right = w;
					break;
				}
				else
				{
					p = p->right;
				}
			}
		}
		w->parent = p;
	}
}
void DFSDelete(BSTNode *& root)
{
	if (root)
	{
		DFSDelete(root->left);
		DFSDelete(root->right);
		delete root;
	}
}

void preorder(BSTNode * root)
{
	if (root)
	{
		cout << root->val << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(BSTNode* root)
{
	if (root)
	{
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}
void postorder(BSTNode* root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->val << " ";

	}
}
void norder(BSTNode* root)
{
	if (root)
	{
		norder(root->right);
		cout << root->val << " ";
		norder(root->left);
	}
}
void DestroyLeafts(BSTNode *& root)
{
	if (root)
	{
		if (root->left == NULL&&root->right == NULL)
		{
			BSTNode * p = root->parent;
			if (p->left == root)
			{
				p->left = NULL;
				
			}
			else p->right = NULL;
			delete root;
			return;
		}
		DestroyLeafts(root->left);
		DestroyLeafts(root->right);
	}
}
BSTNode * BSTSearch(BSTNode * root, int x)
{
	while (root&&root->val!=x)
	{
		if (root->val > x)
		{
			root = root->left;
		}
		else
		{
			root = root->right;
		}
	}
	return root;
}
BSTNode * BSTSearchRekurs(BSTNode*root, int x)
{

	if (root&&root->val != x)
	{
		if (x < root->val)
			return BSTSearchRekurs(root->left, x);
		else
			return BSTSearchRekurs(root->left, x);
	}
}
BSTNode* Nastepnik(BSTNode*root)
{
	if(root==NULL)
	{
		return NULL;
	}
	if (root->right)
	{
		root = root->right;
		while (root->left) root = root->left;
		return root;
	}
	else if (root->parent)
	{
		BSTNode * temp = root->parent;
		while (temp && (root == temp->right))
		{
			root = temp;
			temp = temp->parent;
		}
		return temp;
	}
}
BSTNode * Poprzednik(BSTNode * root)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->left)
	{
		root = root->left;
		while (root->right)
		{
			root = root->right;
		}
		return root;
	}
	else if (root->parent)
	{
		BSTNode * temp = root->parent;
		while (temp->parent&&temp->left == root)
		{
			root = temp;
			temp = temp->parent;

		}
		return temp;
	}
}
void DeleteSubtr(BSTNode* &root)
{
	if (root) {
		DeleteSubtr(root->left);
		DeleteSubtr(root->right);
		if (root->parent)
		{
			BSTNode * p = root->parent;
			if (p->left == root)
			{
				p->left = NULL;
			}
			else p->right = NULL;
		}
		delete root;
	}
}
void RightRotate(BSTNode*&root,BSTNode* A)
{
	BSTNode* p = A->parent;
	BSTNode * B = A->left;
	if (B)
	{
		A->left = B->right;
		if (A->left) A->left->parent=A;
		B->right = A;
		if(p)
		B->parent = p->parent;
		A->parent = B;
		if (p)
		{
			if (p->left == A) p->left = B; else p->right = B;
		}
		else root = B;
	}
}
void LeftRotate(BSTNode*&root, BSTNode*A)
{
	BSTNode *p = A->parent;
	BSTNode * B = A->right;
	if (B)
	{
		A->right = B->left;
		if (A->right) A->right->parent = A;
		B->left = A;
		B->parent = p->parent;
		A->parent = B;
		if (p)
		{
			if (p->left == A) p->left; else p->right = B;
		}
		else root = B;
		}
	}