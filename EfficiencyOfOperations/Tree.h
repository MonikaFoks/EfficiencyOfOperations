#ifndef TREE_H
#define TREE_H
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
	Node *up;
	Node *left;
	Node *right;
	int key;
	char color;
};

class Tree {
public:
	Node Guard;             // Wezel stra¿nika
	Node * root;        // Korzen
	Tree();
	~Tree();
	void remove(Node *p); // Usuwa cale drzewo
	Node *find_element(int keyt); // Wyszukuje wezel
	Node *min_node(Node *p); // Wyszukuje najmniejszy wezel
	Node *next_node(Node *p);// Wyszukuje nastepnik
	void rot_left(Node *A); // Rotacja w lewo
	void rot_right(Node *A); // Rotacja w prawo
	void insert(int keyt);   // Wstawia wezel
	void remove_node(Node *X); // Usuwa wezel
	void read_file(int val); //wczytuje dane
	void printTree(string sp, string sn, Node *p); // Wypisuje drzewo


};

#endif // TREE_H
