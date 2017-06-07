#include<iostream>
#include<string>
using namespace std;
struct BSTNode {
	BSTNode * parent;
	BSTNode * right;
	BSTNode * left;
	int val;
};
void InsertBST(BSTNode*& root, int x);
void DFSRelease(BSTNode*& root);
BSTNode* minBST(BSTNode*&root);
BSTNode* nextBST(BSTNode *root); /*szukanie nastepnika*/
BSTNode* predBST(BSTNode *root);
BSTNode* MaxBST(BSTNode *root);