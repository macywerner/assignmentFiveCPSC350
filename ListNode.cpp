// Logan Welsh
// Student ID: 2325215
// Macy Werner
// Student ID: 2327782
// Assignment 5 CPSC350

#include <cstdlib>	// Gives definition of "NULL"
#include <iostream>
#include <string>
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
	
	if(ln.next == NULL) {
		next = NULL;
	}
	else {
		next = new ListNode<T>(*ln.next);
	}

	if(ln.prev == NULL) {
		prev = NULL;
	}
	else {
		prev = new ListNode<T>(*ln.prev);
	}
}

template <class T>
ListNode<T>::~ListNode() {
	
	if(next != NULL) {	// As it is, recursively deletes all following nodes; Set next to NULL to delete only this node.
		delete next;
	}
}

template <class T>
void ListNode<T>::operator=(const ListNode& ln){
	data = ln.data;
	next = ln.next;
	prev = ln.prev;
}