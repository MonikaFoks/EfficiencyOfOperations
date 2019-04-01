#include "Tree.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string.h>
using namespace std;

Tree::Tree()
{
	Guard.color = 'B';          // Inicjuje straznika
	Guard.up = &Guard;
	Guard.left = &Guard;
	Guard.right = &Guard;
	root = &Guard;           // Korzen wskazuje straznika
}
Tree::~Tree()
{
	remove(root);
}

void Tree::remove(Node * p)
{
	if (p != &Guard)
	{
		remove(p->left);   // usuwamy to co na lewo
		remove(p->right);  // usuwamy to co po prawej
		delete p;              // usuwamy sam wezel
	}
}

void Tree::printTree(string sp, string sn, Node * p)
{
	string t;

	if (p != &Guard)
	{
		t = sp;
		if (sn == "  ") t[t.length() - 2] = ' ';
		printTree(t + "  ", "  ", p->right);

		t = t.substr(0, sp.length() - 2);
		cout << t << sn << p->color << ":" << p->key << endl;

		t = sp;
		if (sn == "  ") t[t.length() - 2] = ' ';
		printTree(t + "  ", "  ", p->left);
	}
}


Node *Tree::find_element(int keyt)
{
	Node * p;

	p = root; //p jest poczotkowo korzeniem
	while ((p != &Guard) && (p->key != keyt)) //tak dlugo jak p nie jest straznikiem oraz p nie jest szukana wartoscia
		if (keyt < p->key) p = p->left; // przesuwamy sie w lewo badz prawo w zaleznosci od stosunku wartosci do wartosci wyszukiwanej
		else           p = p->right;
	if (p == &Guard) return NULL; //jesli nie ma elementu to zwracamy null
	return p;
}


Node * Tree::min_node(Node * p)
{
	if (p != &Guard) // jesli p nie jest straznikiem
		while (p->left != &Guard) p = p->left; //idziemy jak najdalej w prawo
	return p;
}


Node * Tree::next_node(Node * p)
{
	Node * r;

	if (p != &Guard) //jeslli p nie jest straznikiem
	{
		if (p->right != &Guard) return min_node(p->right); //jesli prawe nie jest straznikiem to szukamy najmniejszego na prawo
		else //jesli nastepnik jest na gorze
		{
			r = p->up;
			while ((r != &Guard) && (p == r->right))//szukamy nastepnika w gornych poziomach
			{
				p = r;
				r = r->up;
			}
			return r;
		}
	}
	return &Guard; //jesli nie zostanie znaleziony zwracamy straznika (null)
}


void Tree::rot_left(Node * A)
{
	Node * B, *p;

	B = A->right; //B staje sie prawym dzieckiem A
	if (B != &Guard) //B staje sie lewym dzieckiem A
	{
		p = A->up; //zapamietujemy wskaŸnik na ojca A
		A->right = B->left; //prawe dziecko A staje sie lewym dzieckiem B
		if (A->right != &Guard) A->right->up = A; //ustawiamy ojca dla niegdys lewego dziecka B

		B->left = A; //A stajê siê lewym dzieckiem B
		B->up = p; //B zyskuje ojca A
		A->up = B; //ojcem A staje siê B

		if (p != &Guard) //A nie by³ wczeœniej rootem
		{
			if (p->left == A) p->left = B; else p->right = B;
		}
		else root = B; //jeœli A by³ rootem
	}
}


void Tree::rot_right(Node * A)
{
	Node * B, *p;

	B = A->left;  //B staje sie lewym dzieckiem A
	if (B != &Guard)  //B staje sie lewym dzieckiem A
	{
		p = A->up;   //zapamietujemy wskaŸnik na ojca A
		A->left = B->right; //lewe dziecko A staje sie prawym dzieckiem B
		if (A->left != &Guard) A->left->up = A;  //ustawiamy ojsca dla niegdyæ prawego dziecka B

		B->right = A; //A stajê siê prawym dzieckiem B
		B->up = p;    //B zyskuje ojca A
		A->up = B;    //ojcem A staje siê B

		if (p != &Guard)   //A nie by³ wczeœniej rootem
		{
			if (p->left == A) p->left = B; else p->right = B;
		}
		else root = B; //jeœli A by³ rootem
	}
}


void Tree::insert(int keyt)
{
	Node *X, *Y;

	X = new Node;        // Tworzymy nowy wêze³
	X->left = &Guard;          // pocz¹tkowo dzieci wskazuj¹ na stra¿nika
	X->right = &Guard;
	X->up = root;        //pocz¹tkowo rodzis wskazuje na korzeñ
	X->key = keyt;
	if (X->up == &Guard) root = X; // je¿eli X jest pierwszym elementem w drzewie to staje siê on korzeniem
	else
		while (true)             // je¿eli nie jest pierwszyn elementem
		{
			if (keyt < X->up->key)    // sprawdzamy wartosc rodzina i nowego elementu
			{
				if (X->up->left == &Guard)  //sprzwdzamy czy lewe dziecko jest wolne
				{
					X->up->left = X;  // X staje siê lewym dzieckiem swojefo obecnego rodzica
					break;
				}
				X->up = X->up->left; // schodzimy poziom ni¿ej
			}
			else
			{
				if (X->up->right == &Guard)   //to samo co powy¿ej tylko dla elementu o wiêkszej wartoœci(czyli prawego)
				{
					X->up->right = X;
					break;
				}
				X->up = X->up->right;
			}
		}
	X->color = 'R';         // zawsze nowy element ma kolor czerwony
	while ((X != root) && (X->up->color == 'R'))  //&& wykonuje siê dopóki rodzic jest czerwony
	{
		if (X->up == X->up->up->left) //sprawdzamy czy nas ojciec jest prawym czy lewym elementem
		{
			Y = X->up->up->right; // Y staje siê wujkiem, czyli drugim liœciem ko³o ojca

			if (Y->color == 'R')  // Przypadek 1 - wujek i ojciec maj¹ ten sam kolor
			{
				X->up->color = 'B'; // ojciec i wujek staja sie czarni
				Y->color = 'B';
				X->up->up->color = 'R'; //dziadek staje sie czerwony
				X = X->up->up;          //X staje siê dziadkiem
				continue;               //pêtla kontunuuje siê by sprawdziæ czy przez zmianê koloru dziadka nic sie nie zepsulo
			}

			if (X == X->up->right) // Przypadek 2 - jeœli nowy element jest prawym dzieckiem
			{
				X = X->up;          //X staje siê ojcem
				rot_left(X);           //rotujemy w lewo
			}
			// Przypadek 3 -  nowy element jest lewym dzieckiem lub po rotacji nowy element staje siê lewym dzieckiem
			X->up->color = 'B';   //rodzica kolorujemy na czarno
			X->up->up->color = 'R'; //dziadek na czerwono
			rot_right(X->up->up);     //rotacja w prawo dziadka
			break;
		}
		else
		{                  // Przypadki lustrzane
			Y = X->up->up->left;

			if (Y->color == 'R') // Przypadek 1
			{
				X->up->color = 'B';
				Y->color = 'B';
				X->up->up->color = 'R';
				X = X->up->up;
				continue;
			}

			if (X == X->up->left) // Przypadek 2
			{
				X = X->up;
				rot_right(X);
			}

			X->up->color = 'B'; // Przypadek 3
			X->up->up->color = 'R';
			rot_left(X->up->up);
			break;
		}
	}
	root->color = 'B'; //root zawsze musi byæ czarny
}

void Tree::remove_node(Node * X)
{
	if (X)
	{
		Node * W, *Y, *Z;

		if ((X->left == &Guard) || (X->right == &Guard)) Y = X; //jezeli X nie ma potomka lub ma jednego, wtedy Y staje sie X
		else                                    Y = next_node(X); //jezeli nie Y staje siê nastêpnikiem X

		if (Y->left != &Guard) Z = Y->left; //je¿eli Y ma lewego potomka to Z staje siê lewym dzieckiem Y
		else              Z = Y->right;//jesli nie to Z staje sie prawym potomkiem Y

		Z->up = Y->up;  //

		if (Y->up == &Guard) root = Z;
		else if (Y == Y->up->left) Y->up->left = Z;
		else                      Y->up->right = Z;

		if (Y != X) X->key = Y->key;

		if (Y->color == 'B')   // Naprawa struktury drzewa czerwono-czarnego
			while ((Z != root) && (Z->color == 'B'))
				if (Z == Z->up->left)
				{
					W = Z->up->right;

					if (W->color == 'R')
					{              // Przypadek 1
						W->color = 'B';
						Z->up->color = 'R';
						rot_left(Z->up);
						W = Z->up->right;
					}

					if ((W->left->color == 'B') && (W->right->color == 'B'))
					{              // Przypadek 2
						W->color = 'R';
						Z = Z->up;
						continue;
					}

					if (W->right->color == 'B')
					{              // Przypadek 3
						W->left->color = 'B';
						W->color = 'R';
						rot_right(W);
						W = Z->up->right;
					}

					W->color = Z->up->color; // Przypadek 4
					Z->up->color = 'B';
					W->right->color = 'B';
					rot_left(Z->up);
					Z = root;         // To spowoduje zakonczenie petli
				}
				else
				{                // Przypadki lustrzane
					W = Z->up->left;

					if (W->color == 'R')
					{              // Przypadek 1
						W->color = 'B';
						Z->up->color = 'R';
						rot_right(Z->up);
						W = Z->up->left;
					}

					if ((W->left->color == 'B') && (W->right->color == 'B'))
					{              // Przypadek 2
						W->color = 'R';
						Z = Z->up;
						continue;
					}

					if (W->left->color == 'B')
					{              // Przypadek 3
						W->right->color = 'B';
						W->color = 'R';
						rot_left(W);
						W = Z->up->left;
					}

					W->color = Z->up->color;  // Przypadek 4
					Z->up->color = 'B';
					W->left->color = 'B';
					rot_right(Z->up);
					Z = root;         // To spowoduje zakonczenie petli
				}

		Z->color = 'B';

		delete Y;
	}
}

void Tree::read_file(int val) //takie samo jak w innych strukturach
{
	string stri;
	fstream file("20000.txt", ios::in);
	if (file.good())
	{
		for (int i = 0; i < val; i++)
		{
			getline(file, stri);
			char tmp[sizeof(stri)];
			strcpy_s(tmp, stri.c_str());
			int number = atoi(tmp);
			insert(number);
		}
		file.close();
	}

}


