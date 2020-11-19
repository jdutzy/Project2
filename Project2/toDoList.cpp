#include <iostream> 
#include <string> 
#include <ctime> 
#include <fstream>
#include <iomanip>
#include "toDoList.h"
#include "toDoItem.h"

using namespace std;

Node::Node(){
	nodeValue = 0;
	head = NULL;
	temp = NULL;
	curr = NULL;
	tail = NULL;
	nodeCount = 0;
}

Node::Node(const Node& b)
{
	nodePtr newNodePtr = new Node;
	nodePtr nodeCopy = b.head;
	newNodePtr = nodeCopy;
	head = newNodePtr;
	tail = newNodePtr;
	nodeCount++;
	nodeCopy = nodeCopy->getNext();
	while (tail != b.tail)
	{
		nodePtr newNode = new Node;
		newNode = nodeCopy;
		nodePtr currentNode = tail;
		currentNode->setNext(newNode);
		tail = newNode;
		nodeCount++;
		nodeCopy = nodeCopy->getNext();
	}
}

Node::~Node()
{
	this->clearNode();
}

void Node::setNext(node* node) {
	this->Next = node;
}

Node& Node::operator=(const Node& rho)
{
	this->clearNode();
	this->copyNode(rho);
	return *this;
}

void Node::clearNode()
{
	nodePtr current = head;
	while (current != nullptr)
	{
		current = pop_front();
		delete current;
		current = head;
	}
	head = nullptr;
	tail = nullptr;
}

void Node::copyNode(const Node& b)
{
	head = nullptr;
	tail = nullptr;
	nodeCount = 0;
	nodePtr headNode = b.gethead();
	while (headNode != nullptr)
	{
		string des = headNode->getDescription();
		Node* newNode = new Node(des);
		push_back(newNode);
		headNode = headNode->getNext();
	}
}

Node* Node::pop_front()
{
	nodePtr savehead = head;
	head = head->getNext();
	nodeCount--;
	return savehead;
}

void Node::push_back(nodePtr newNode)
{
	if (nodeCount == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		nodePtr currentNode = tail;
		currentNode->setNext(newNode);
		tail = newNode;
	}
	nodeCount++;
}


void Node::printlist(Node* front){
	Node* temp = front;

	while (temp != NULL){
		cout << temp->nodeValue;
		temp = temp->Next;
	}
}

void Node::printback(Node* front){
	Node* temp;
	temp = front;


	if (front == NULL){
		return;
	}
	else if (front->Next == NULL){
		cout << front->nodeValue;
		return;
	}
	else{
		printback(front->Next);
		cout << temp->nodeValue;
	}
}

Node* Node::searchlist(Node* front, int value){
	Node* temp = front;

	while (temp != NULL){
		if (value == temp->nodeValue)
			return temp;
		temp = temp->Next;
	}return NULL;
}

void Node::deleteNode(Node* &front, int value){

	Node* curr, *prev;

	curr = front;
	prev = NULL;
	bool found = false;

	while (curr != NULL & !found){

		if (curr->nodeValue == found){
			if (prev == NULL){
				front = front->Next;
			}
			else{
				prev->Next = curr->Next;
			}
			delete curr;
			found = true;
		}
		else{
			prev = curr;
			curr = curr->Next;
		}
	}

}

void Node::insertNode(Node* &front, int value){

	Node* newNode = new Node(value);

	if (front == NULL){
		front = newNode;
		return;
	}

	Node* curr = front;
	Node* prev = NULL;

	while (curr != NULL && curr->nodeValue < value){
		prev = curr;
		curr = curr->Next;
	}
	if (prev == NULL){
		newNode->Next = front;
		front = newNode;
	}
	else if (curr == NULL){
		prev->Next = newNode;
	}
	else{
		prev->Next = newNode;
		newNode->Next = curr;
	}
}


int Node::countlist(Node* front){
	int total = 0;
	Node* curr = front;

	while (curr != NULL){
		total++;
		curr = curr->Next;
	}
	return total;
}

void Node::setNext(node* Next)
{
}

