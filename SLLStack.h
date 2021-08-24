//SLLStack.h file
//Description: This class models a linked list

//This class has been made using help from the sample code that Dr.Bita Shadgar has 
//provided us in the class.

#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <stdexcept>
// class prototype
template <typename T>
class SLL;


// Class Node
template <typename T>
class Node {
public:
	Node() {
	    next = nullptr;
	}
	Node(T data, Node<T> * link = nullptr){
	    info = data; 
        next = link;
	}
	
	friend class SLL<T>;

private:	
	T info;
	Node <T> *next;
};



// classs SLL
template<typename T>
class SLL {
public: 
	SLL(){
		head = tail = nullptr;
		size = 0;
	}
	~SLL() {
       for (Node<T> *tmp; head != nullptr;  ) {
    		tmp = head;
    		head = head->next;
    		delete tmp; 
    		tmp = nullptr; 
    	}	
    }
	void addFirst(T data);
	
	T removeFirst();
	T front();


private:
	Node<T> *head;
	Node<T> *tail;
	long size;
};


//returns the top element of the stack.
template<typename T>
T SLL<T>::front(){
	T data = head -> info;
	return data;
}


//adds at the front of the stack.
template<typename T>
void SLL<T>::addFirst(T data){
	Node<T>* temp;
	if (head == nullptr){ //special case
	   temp = new Node<T>(data, nullptr);
	   head = tail = temp;
	   size++; 
	}
	else{
	   temp = new Node<T>(data, head); 
	   head = temp;  
	   size++;  
	}
}



//removes from the top of the stack.
template<typename T>
T SLL<T>::removeFirst(){
	if (head == nullptr)
		throw std::runtime_error("ERROR: Empty List!"); 
	Node<T>* temp = head; 
	head = head -> next; 
	if (head == nullptr) //Special Case
	   tail = nullptr;
	T data = temp -> info;
	delete temp;
	temp = nullptr; 
	size--;  
	return data;
}


#endif
