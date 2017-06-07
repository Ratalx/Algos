#include<iostream>
struct node{
	int val;
	node * next;
};
void Add(node * &h, int x);
void Delete(node * &h);
void ListShow(node *h);
int LastToHead(node * &h);
void HeadLastSwap(node *&h);
void SwapAfterX(node *&h, int x);
void SWAP(node *&h, node *p=NULL);
void SwapBeforeX(node *&h, int x);
void DeleteAteven(node *&h);
void DelNAfterX(node *&h, int x,int n);
void LBubleSort(node *&h);
void ListReverse(node *&h);
void CopyAfter(node *&h);
void AddSort(node*&h, int x);
