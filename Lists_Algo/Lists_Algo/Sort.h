#include<iostream>
using namespace std;
/*Metody Proste*/
void BubbleSort(int* tab,int n);
void CoctailSort(int* tab, int n);
void InsertSort(int* arr, int n);
void SelectSort(int *arr, int n);
void CombSort(int *arr, int n);
int NewGap(int gap);
void ShellSort(int *arr, int n);
/*Metody Szybkie*/
void MergeSort(int *arr, int start,int end);
void Merge(int *arr, int start,int mid, int end);