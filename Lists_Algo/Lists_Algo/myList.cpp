#include "myList.h"

void Add(node *& h, int x)
{
	node * p = new node;
	p->next = h;
	p->val = x;
	h = p;
}

void Delete(node *& h)
{
	if (h != NULL)
	{
		node * p = h;
		h = h->next;
		delete p;
	}
}

void ListShow(node * h)
{
	node * p = h;
	std::cout << "H->";
	while (p != NULL)
	{
		std::cout << p->val << "->";
		p = p->next;

	}
	std::cout << "NULL \n";
	system("pause");
}

int LastToHead(node *& h)
{
	int i = 1;
	node *p = h;
	while (p->next->next != NULL)
	{
		i++;
		p=p->next;
	}
	i++;
	node * temp = p->next;
	temp->next = h;
	h = temp;
	p->next = NULL;
	return i;
}

void HeadLastSwap(node *& h)
{
	node *p = h;
	while (p->next->next != NULL)
	{
		p=p->next;
	}
	node * temp = p->next;
	temp->next = h->next;
	p->next = h;
	h->next = NULL;
	h = temp;
}

void SwapAfterX(node *& h, int x)
{
	Add(h, 0);
	node * p = h;
	while (p!= NULL&&p->next!=NULL)
	{
		if (p->next->val == x)
		{
			SWAP(p,p);
			p=p->next;
		}
		if(p!=NULL)
		p = p->next;
	}
	Delete(h);
}

void SWAP(node *& h, node * p)
{
	if (p == NULL)
	{
		p = h->next;
		h->next=p->next;
		p->next = h;
		h = p;
	}
	else if(p->next!=NULL&&p->next->next!=NULL)
	{
		
		node *temp = p->next;
		p->next = temp->next;
		temp->next = p->next->next;
		p->next->next = temp;
	}
}

void SwapBeforeX(node *& h, int x)
{
	Add(h, 0);
	if (h->next->next!=NULL)
	{
		node*p = h->next->next;
		node *p2 = h;
		while (p != NULL)
		{
			if (p->val == x)
			{
				SWAP(p2, p2);
				break;
			}
			p = p->next;
			p2 = p2->next;
		}
	}
	Delete(h);
}

void DeleteAteven(node *& h)
{
	bool even = false;
	node *p = h;
	while (p->next!= NULL)
	{
		node * temp = p->next;
		p->next = temp->next;
		p = p->next;
		delete temp;
		
	}
	
}

void DelNAfterX(node *& h, int x,int n)
{
	node * p = h;
	while (p!=NULL)
	{
		if (p->val == x)
		{
			while (n > 0)
			{
				node *temp = p->next;
				p->next = temp->next;
				delete temp;
				n--;
			}
			break;
		}
		p=p->next;
	}

}
void LBubleSort(node *&h)
{
	Add(h, 0);
	node * p = h;
	node * temp = h;
	bool swap = true;
	while (swap)
	{	
		p = h;
		swap = false;
		while (p != NULL&&p->next != NULL&&p->next->next)
		{
			if (p->next->val > p->next->next->val)
			{
				SWAP(p, p);
				p = p->next;
				swap = true;
			}
			else p = p->next;
		}
	}
	Delete(h);
	
}
void ListReverse(node *&h)//funckja dziala na zasadzie wrzucania na poczatek listy kolejnych elementow 
{
	node *p;
	node *temp;
	if (h)
	{
		p = h;
		while (p->next!=NULL)
		{
			temp= p->next;
			p->next = temp->next;
			temp->next = h;
			h = temp;
		}
	}
}
void CopyAfter(node *&h)
{
	node *p = h;
	node * Ltemp = NULL;
	while (p->next!= NULL)
	{
		Add(Ltemp, p->val);
		p = p->next;
	}
	Add(Ltemp, p->val);
	ListReverse(Ltemp);
	p->next = Ltemp;
}
void AddSort(node*&h, int x)
{
	if (h == NULL)
	{
		Add(h, x);
	}
	else if (h->next == NULL)
	{
		if (h->val < x)
		{
			node *p = new node;
			p->val = x;
			p->next = NULL;
			h->next = p;
		}
		else
		{
			Add(h, x);
		}
	}
	else
	{
		node *temp = h;
		bool s = false;
		if (h->val > x)
		{
			Add(h, x);
		}
		else {
			while (temp->next != NULL)
			{
				if (x < temp->next->val)
				{
					Add(temp->next, x);
					break;
					s = true;
				}
				temp = temp->next;
			}
			if (s == false && temp->next == NULL)
			{
				node *p = new node;
				p->val = x;
				temp->next = p;
				p->next = NULL;
			}
		}
	}
}

