#include "Sort.h"

void BubbleSort(int * arr,int n)
{
	bool a;
	for(int i=0;i<n-1;++i)
	{
		a = false;
		for (int j = 0; j < n - 1-i; ++j)
		{

			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				a = true;
			}
		}
		if(!a)
		{
			break;
		}
	}

}
void CoctailSort(int* arr, int n)
{
	int first = 0;
	int last = n - 1;
	bool is_swap = true;
	while (is_swap)
	{
		is_swap = false;
		for (int i = first; i < last; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
					is_swap = true;
			}
		}
		last--;
		for (int i = last; i > first; --i)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(arr[i], arr[i - 1]);
					is_swap = true;
			}
		}
		first++;


	}



}
void InsertSort(int* arr, int n)
{
	for (int i = 1; i < n; ++i)
	{
		int x = arr[i];
		int j = i - 1;
		for (; j >= 0 && arr[j] > x; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = x;
	}
}
void SelectSort(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min=arr[i];
		int imin = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				imin = j;
			}
		}
		if (i != imin)
		swap(arr[i], arr[imin]);

	}


}
void CombSort(int *arr, int n)
{
	int gap = n;
	while (true)
	{
		gap = NewGap(gap);
		if (gap == 1) break;
		for (int i = 0; i < n - gap; ++i)
		{
			int j = i + gap;
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
	BubbleSort(arr, n);
}
int NewGap(int gap)
{
	gap = (gap * 10) / 13;
	if (gap == 9 || gap == 10)
		gap = 11;
	if (gap < 1)
		gap = 1;
	return gap;
}/*Funckja do sortowania grzebieniowego do tworzenia rozpietosci "grzebienia"(combsort)*/
void ShellSort(int *arr, int n)/*wedlug Knutha*/
{
	int h = 1;
	for (; h < n; h = 3 * h + 1);
	h /= 9;
	if (!h)	h++;
	for (; h > 0; h /= 3)
	{
		for (int j = h; j < n; ++j)
		{
			int x = arr[j];
			int i = j - h;
			for (; i >= 0 && x < arr[i]; i -= h)
			{
				arr[h + i] = arr[i];
			}
			arr[i + h] = x;
		}
	}
}
void MergeSort(int *arr, int start,int end)
{
	int mid;
	if (start != end)
	{
		mid = (start+end) / 2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);
		Merge(arr, start, mid, end);
	}
}
void Merge(int *arr, int start, int mid, int end)
{
	int *temp = new int[(end - start)];
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end)
	{
		if (arr[j] < arr[i])
		{
			temp[k] = arr[j];
			j++;
		}
		else
		{
			temp[k] = arr[i];
			i++;
		}
		k++;
	}
	if (i <= mid)
	{
		while (i <= mid)
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
	}
	else
	{
		while (j <= end)
		{
			temp[k] = arr[j];
			j++;
			k++;
		}
	}
	for (i = 0; i <= end - start; ++i)
	{
		arr[start + i] = temp[i];
	};
	delete temp;
}