#include<iostream>
using namespace std;
struct BSTNode {
	BSTNode * parent;
	BSTNode * right;
	BSTNode * left;
	int val;
};
void myInsertBST(BSTNode* &root, int x);
void DFSDelete(BSTNode* &root);
void preorder(BSTNode* root);
void inorder(BSTNode* root);
void postorder(BSTNode* root);
void norder(BSTNode* root);
void DestroyLeafts(BSTNode* &root);
BSTNode * BSTSearch(BSTNode * root, int x);
BSTNode * BSTSearchRekurs(BSTNode*root, int x);
BSTNode* Nastepnik(BSTNode*root);
BSTNode * Poprzednik(BSTNode * root);
void DeleteSubtr(BSTNode* &root);
void RightRotate(BSTNode*&root,BSTNode * A);
void LeftRotate(BSTNode*&root, BSTNode*A);