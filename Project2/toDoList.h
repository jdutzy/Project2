#pragma once
#define toDoList_h
#include <iostream> 
#include <string> 
#include <ctime> 
#include <fstream>
#include <iomanip>
using namespace std;

class Node {
private:
	typedef struct node {
		string data;
		node* Next;
	}* nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;
	nodePtr tail;
	int nodeCount, nodeValue;

public:

	Node();

	Node(const Node& b);
	~Node();
	Node& operator=(const Node& rho);
	void clearNode();
	void copyNode(const Node& b);
	Node* pop_front();
	void push_back(nodePtr newNode);
	void printlist(Node* front);
	void printback(Node* front);
	Node* searchlist(Node* front, int value);
	void deleteNode(Node*& front, int value);
	void insertNode(Node*& front, int value);
	int countlist(Node* front);

	int getNext();
	void setNext(node* node);

	int gethead();


}