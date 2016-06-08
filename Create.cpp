#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *pNext;
};
typedef struct Node NODE;

struct Stack
{
	NODE *Top;
};
typedef struct Stack STACK;

void Init(STACK &s)
{
	s.Top = NULL;
}

NODE *GetNode(int x)
{
	NODE *p = new NODE;
	if(p == NULL)
	{
		exit(0);
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

bool isEmpty(STACK s)
{
	if(s.Top == NULL)
		return true;//there is no data in stack
	return false;
}

bool Push(STACK &s, NODE *p)
{
	if(p == NULL)
	{
		exit(0);
	}
	if(s.Top == NULL)
	{
		s.Top = p;
	}
	else
	{
		p->pNext = s.Top;
		s.Top = p;
	}
	return true;
}

bool Pop(STACK &s)
{
	NODE *p = s.Top;
	s.Top = s.Top->pNext;
	delete p;
	return true;
}

int Top(STACK s)
{
	return s.Top->data;
}

void InputStack(STACK &s)
{
	Init(s);
	int n;
	cout << "\nInput elements: ";
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		int x;
		cout << "\nInput data: ";
		cin >> x;
		NODE *p = GetNode(x);
		Push(s, p);
	}
}

void OutputStack(STACK &s)
{
	while(!isEmpty(s))
	{
		int x = Top(s);
		Pop(s);
		cout << x << "   ";
	}
}

int main()
{
	STACK s;
	InputStack(s);
	OutputStack(s);
	return 0;
}