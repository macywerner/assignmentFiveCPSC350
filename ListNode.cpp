// CPSC-350-01 Assignment 4
// ListNode.cpp
// Template class for a node in a doubly-linked list.
// Logan Welsh
// 04/18/2020

#include <cstdlib>	// Gives definition of "NULL"

template <class T>
class ListNode {

	public:
	
		T data;	// Data to store in the node
		ListNode *next;	// Pointer to next node
		ListNode *prev;	// Pointer to previous node
		
		ListNode();	// Default constructor
		ListNode(T val);	// Overloaded constructor
		ListNode(const ListNode& ln);	// Copy constructor
		~ListNode();	// Destructor
		
		void operator=(const ListNode& ln);

};

template <class T>
ListNode<T>::ListNode() {	
	data = NULL;
	next = NULL;	// may need to replace NULL with nullptr
	prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T val) {
	data = val;
	next = NULL;
	prev = NULL;
}

template <class T>
ListNode<T>::ListNode(const ListNode& ln) {
	data = ln.data;
	next = ln.next;
	prev = ln.prev;
}

template <class T>
ListNode<T>::~ListNode() {
	if(next != NULL) {	// As it is, recursively deletes all following nodes; Set next to NULL to delete only this node.
		delete next;
	}
	// The following line is commented-out to allow custom objects (non-pointers) to be used in the doubly-linked lists.
	//delete data;
}

template <class T>
void ListNode<T>::operator=(const ListNode& ln){
	data = ln.data;
	next = ln.next;
	prev = ln.prev;
}