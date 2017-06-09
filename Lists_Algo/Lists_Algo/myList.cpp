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
	node * p = h;
	node * temp = h;
	node * nu = NULL;
	bool swap = true;
	while (swap)
	{	
		swap = false;
		p = h;
		if (p->val > p->next->val)
		{
			SWAP(h, nu);
			swap = true;
		}
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
void CopyifGX(node* &h, int x)
{
	if (h)														//sprawdzamy czy pusta
	{							
		node *p=h;
		while (p == h)											//jesli jest na headzie i kilka elementow po kolei bedzie mniejszych od x 
		{
			if (p->val < x)
			{
				Delete(h);										//usuwamy w headzie i zmieniamy p =nowe h
				p = h;
			}
			else
			{
				Add(p->next, p->val);							//dodajemy elemnt i za niego przesuwamy sie	na niego	
				p = p->next;
			}
		}
		while (p->next)											//przechodzmimy przez liste
		{
			if (p->next->val < x)								
			{
					node *temp = p->next;
					p->next = temp->next;						//usuwamy przy okazji modyfikujac wskaznik
					delete temp;
			}
			else
			{
				p=p->next;									//przesuwamy sie na element ktory sprawdzilismy
				Add(p->next, p->val);						// dodajemy nowy element i przesuwamy sie na niego
				p = p->next;
			}
		}
	}
}
void myReversList(node *&h)
{
	if (h)
	{
		node *p = h;
		while (p->next)
		{
			node *temp = p->next;
			p->next = temp->next;
			temp->next = h;
			h = temp;

		}
	}
}
void CopyAfterRev(node*&h)
{
	node*p = h;
	node * temp = NULL;
	while (p->next)
	{
		Add(temp, p->val);
		p = p->next;
	}
	Add(temp, p->val);
	p->next = temp;

}
void SwapMinMax(node*&h)
{
	if (h)
	{
		node*p = h;
		node *pmax = new node;
		node *pmin = new node;
		pmax->next = h;
		pmin->next = h;
		while (p->next)
		{
			if (p->next->val > pmax->next->val)
				pmax = p;
			if (p->next->val < pmin->next->val)
				pmin = p;
			p=p->next;
		}
		if (pmax == pmin->next)
		{
			node*temp = pmin->next;
			pmin->next = temp->next;
			temp->next = pmin->next->next;
			pmin->next->next = temp;
		}
		else if (pmin == pmax->next)
		{
			node* temp = pmax->next;
			pmax->next = temp->next;
			temp->next = pmax->next->next;
			pmax->next->next = temp;
		}
		else
		{
			node *min = pmin->next;
			node *amax = pmax->next->next;
			pmax->next = min->next;
			pmin->next = pmax->next;
			pmax->next = min;
			min->next = amax;
		}
	}
}