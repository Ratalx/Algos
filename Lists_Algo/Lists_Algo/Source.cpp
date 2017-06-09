#include<iostream>
#include<ctime>
#include<string>
#include"myList.h"
#include"Sort.h"
#include"myBST.h"
string cr, cl, cp;
void printBT(string sp, string sn, BSTNode * v);
int main()
{
	srand(time(NULL));
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	BSTNode *root = NULL;
	int i, k;
	myInsertBST(root, 25);
	myInsertBST(root, 19);
	for (i = 0; i < 10; ++i)
	{
		myInsertBST(root, rand() % 50 + 1);
	}
	cout << "\n\n";
	printBT("", "", root);
	cout << "\n\n";
	RightRotate(root,root->right);
	cout << "\n\n";
	printBT("", "", root);
	system("pause");
	return 0;
}


void printBT(string sp, string sn, BSTNode * v)
{
	string s;

	if (v)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printBT(s + cp, cr, v->right);

		s = s.substr(0, sp.length() - 2);
		cout << s << sn << v->val << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printBT(s + cp, cl, v->left);
	}
}



//
///*node *h = NULL;
//int tab[10];
//for (int i = 11; i >0; --i)
//{
//AddSort(h, rand()%30+1);
//}*/
//int tab[10];
//for (int i = 0; i <10; ++i)
//{
//	tab[i] = rand() % 20 + 1;
//}
//for (int i = 0; i < 10; ++i)
//{
//	cout << "tab[" << i << "]= " << tab[i] << endl;
//}
//
//MergeSort(tab, 0, 9);
//cout << "\n\n";
//for (int i = 0; i < 10; ++i)
//{
//	cout << "tab[" << i << "]= " << tab[i] << endl;
//}
//system("pause");
//

