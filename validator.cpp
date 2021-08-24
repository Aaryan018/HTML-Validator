//ER.h file
//Description: This program checks whether an HTML file is valid or not
//Author: Aaryan Gupta


#include<iostream>
#include<string>
#include <stdexcept>
#include<fstream>

#include "SLLStack.h"
#include "LinkedStack.h"

using namespace std;


//function that checks if tag-open elements are valid or not.
bool  isOpening(string& s){

	string word = "";


	int i = 0;
	int j = s.length() - 1;

	while(s[i] == ' ' || s[i] == '\t' || s[i] == '\n'){
		i = i + 1;
	}

	while(s[j] == ' ' || s[j] == '\t' || s[j] == '\n'){
		j = j - 1;
	}


	while(i <= j){
		word += s[i];
		i = i + 1;
	}

	if(word == "head" || word == "html" || word == "body" || word == "p" || word == "br" || word == "li" || word == "h1" || word == "h2" || word == "ul" || word == "ol"){
		s = word;
		return true;
	}
	else{
		return false;
	}
}


//function that checks is closing tags are valid or not.
bool isClosing(string& s){

	string word = "";

	if(s[0] != '/'){
		return false;
	}
	
	int i = 1;
	int j = s.length() - 1;

	while(s[i] == ' ' || s[i] == '\t' || s[i] == '\n'){
		i = i + 1;
	}

	while(s[j] == ' ' || s[j] == '\t' || s[j] == '\n'){
		j = j - 1;
	}

	while(i <= j){
		word += s[i];
		i = i + 1;
	}

	if(word == "head" || word == "html" || word == "body" || word == "p" || word == "br" || word == "li" || word == "h1" || word == "h2" || word == "ul" || word == "ol"){
		s = word;
		return true;
	}
	else{
		return false;
	}
}


//function that checks whether emoty tags are valid or not.
bool isEmptyTag(string& s){

	string word = "";

	if(s[s.length() - 1] != '/'){
		return false;
	}
	
	int i = 0;
	int j = s.length() - 2;

	while(s[i] == ' ' || s[i] == '\t' || s[i] == '\n'){
		i = i + 1;
	}

	while(s[j] == ' ' || s[j] == '\t' || s[j] == '\n'){
		j = j - 1;
	}

	while(i <= j){
		word += s[i];
		i = i + 1;
	}

	if(word == "head" || word == "html" || word == "body" || word == "p" || word == "br" || word == "li" || word == "h1" || word == "h2" || word == "ul" || word == "ol"){
		s = word; 
		return true;
	}
	else{
		return false;
	}

}

//function that calls other 3 functions to check the validity of the tags
int isValid(string& tag){

	if(tag == ""){
		return 3;
	}

	if(isOpening(tag)){
		return 1;
	}
	else if(isClosing(tag)){
		return 2;
	}
	else if(isEmptyTag(tag)){
		return 3;
	}
	else{
		return 0;
	}


}


//this function reads in the file and calls other supporting functions to 
//check wheter html file is valid or not.
int main(){

	ifstream in;
	in.open("testfile.txt");

	LinkedStack<string> stack;

	

	if(in.is_open()){

		string tag = "";
		string waste = "";
		int n;

		while(!in.eof()){

			tag = "";

			getline(in, waste, '<');
			getline(in, tag, '>');

			n = isValid(tag);

			if(n == 1){
				stack.push(tag);

			}
			else if(n == 2){

				if(tag == stack.top()){
					stack.pop();
				}
				else{
					cout << "Invalid: Tags are Crossing" << endl;
					exit(1);
				}

			}
			else if(n == 0){
				cout << "Invalid File Due to Invalid Tag" << endl;
				exit(1);
			}
		}

		cout << "File is Valid" << endl;		

	}
}
