//LinkedStack.h file
//Description: This class models a stack
//Author: Aaryan Gupta
//Creation Date: June 5, 2021


#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include<iostream>
#include "SLLStack.h"

using namespace std;

template<typename T>
class LinkedStack{

	public:

		//constructor
		LinkedStack();

		//destructor
		~LinkedStack();

		//returns the size of the stack
		int size() const;

		//returns truw if stack is empty
		bool empty() const;

		//returns the element at the top ofthe stack
		const T top();

		//adds the element at the top of the stack
		void push(const T& e);

		//removes the element at the top of tyhe stack.
		const T pop();

	private:

		//linked list of elements
		SLL<T> S;

		//size of stack
		int n;
};


//constructor
template<typename T>
LinkedStack<T>::LinkedStack(){
	n = 0;

}

//destructor
template<typename T>
LinkedStack<T>::~LinkedStack(){

}


//returns the size of the stack
template<typename T>
int LinkedStack<T>::size() const{
	return n;
}


//returns true if the stack is empty
template<typename T>
bool LinkedStack<T>::empty() const{
	return n==0;
}


//returns the top of the stack. AARYAN check this later
template<typename T>
const T LinkedStack<T>::top(){

	if(empty()){
		cout << "Empty Stack" << endl;
		exit(1);
	}

	return S.front();

}


//adds to the front of the stack.
template<typename T>
void LinkedStack<T>::push(const T& e){

	++n;
	S.addFirst(e);

}


//removes the front element.
template<typename T>
const T LinkedStack<T>::pop(){

	if(empty()){
		cout << "Empty Stack" << endl;
		exit(1);
	}
	--n;
	return S.removeFirst();
}

#endif