#include  <iostream>
#include  <windows.h>
#include  <cstdlib>
#include  <time.h>
#include  <stdio.h>
#include  "string"

using namespace std;

struct node
{
	int x;
	node* L = NULL;
	node* R = NULL;
};

string PrintSpaces(int level)
{
	string spaces = "";

	for (int i = 0; i < level; i++)
	{
		spaces = spaces + "   ";
	}
	return spaces;
}

void ShowAll(node* J, int level)
{
	cout << J->x << endl;
	level++;

		if (J->L != NULL)
		{
			cout << PrintSpaces(level) << "L:";
			ShowAll(J->L, level);
		}
		if (J->R != NULL)
		{
			cout << PrintSpaces(level) << "R:";
			ShowAll(J->R, level);
		}

}

void InOrder(node*&root)
{
	if (root != NULL)
	{
		InOrder(root->L);
		cout << root->x << ",  ";
		InOrder(root->R);
	}
}

void PreOrder(node*&root)
{
	cout << root->x << ",  ";
	InOrder(root->L);
	InOrder(root->R);
}

node* Search(node*&root, int z)
{
	if (root != NULL)
	{
		if (root->x == z)
		{
			return root;
		}
		else
		{
			if(z < root->x)
			{
				Search(root->L, z);
			}
			else
			{
				Search(root->R, z);
			}
		}
	}
	else
	{
		return NULL;
	}



}
void AddBst(node*&root, int z)
{
	node* J = root;

	while (J != NULL)
	{
		if (z < J->x)
		{
			if (J->L != NULL)
			{
				J = J->L;
			}
			else
			{
				node* N = new node;
				N->x = z;
				J->L = N;
				break;
			}
		}
		else
		{
			if (J->R != NULL)
			{
				J = J->R;
			}
			else
			{
				node* N = new node;
				N->x = z;
				J->R = N;
				break;
			}
		}
	}
}


int main()
{
	node* root = new node;
	root->x = 100;

	AddBst(root, 120);
	AddBst(root, 80);
	AddBst(root, 5);
	AddBst(root, 290);
	AddBst(root, 101);
	AddBst(root, 156);
	AddBst(root, 67);
	AddBst(root, 98);
	AddBst(root, 2);
	AddBst(root, -5);
	AddBst(root, 167);
	AddBst(root, 12);
	AddBst(root, 135);
	AddBst(root, 420);
	AddBst(root, 56);
	AddBst(root, 150);
	AddBst(root, 50);
	AddBst(root, -10);


	ShowAll(root, 0);
	cout << endl;


	InOrder(root);
	cout << endl;
	PreOrder(root);
	cout << endl;


	int b = NULL;
	cout << "Podaj jaka liczbe chcesz znalezc: ";
	cin >> b;

	node* A = Search(root, b);

		if (A != NULL)
		{
			cout << A->x << endl;
		}
		else
		{
			cout << "Nie ma oczekiwanej wartosci!" << endl;
		}

	system("pause");

    return 0;
}
