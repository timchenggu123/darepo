/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  uwuserid @uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  (Winter|Spring|Fall) 201N
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    -
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    -
 *****************************************/

#ifndef TRIE_H
#define TRIE_H

#ifndef nullptr
#define nullptr 0
#endif

#include "ece250.h"
#include "Trie_node.h"
#include "Exception.h"
#include <iostream>
#include <string>
#include <cctype>

class Trie {
	private:
		Trie_node *root_node;
		int trie_size;

	public:
		Trie();
		~Trie();

		// Accessors

		int size() const;
		bool empty() const;
		bool member( std::string const & ) const;
		Trie_node *root() const;
		// Mutators

		bool insert( std::string const & );
		bool erase( std::string const & );
		void clear();

	// Friends

	friend std::ostream &operator<<( std::ostream &, Trie const & );
};

Trie::Trie():
root_node( nullptr ),
trie_size( 0 ) {
	// empty constructor
}

Trie::~Trie() {
	clear();
}

int Trie::size() const {
	return trie_size;
}

bool Trie::empty() const {
	if(size() == 0){
		return true;
	}
	return false;
}

Trie_node *Trie::root() const {
	return root_node;
}

bool Trie::member( std::string const &str ) const {
	if (root() == nullptr){
		return false;
	}
	std::string str1 = str;
	for (int i = 0; i < str1.length(); i++) {
		str1[i] = toupper(str1[i]);
		int value = (int)str1[i];
		if (value < 65 || value >90) {
			throw illegal_argument();
		}
	}
	return root_node->member(str1,0);
}

bool Trie::insert( std::string const &str ) {
	std::string str1 = str;
	if (root() == nullptr){
		root_node = new Trie_node();
	}
	for (int i = 0; i < str1.length(); i++) {
		str1[i] = toupper(str1[i]);
		int value = (int) str1[i];
		if ( value <65 || value >90){
			throw illegal_argument();
		}
	}
	if (root() -> insert(str1,0)){
		++trie_size;
		return true;
	}
	return false;
}

bool Trie::erase( std::string const &str ) {
	if (size() == 0){
		return false;
	}
	std::string str1 = str;
	for (int i = 0; i < str1.length(); i++) {
		str1[i] = toupper(str1[i]);
		int value = (int) str1[i];
		if (value < 65 || value >90) {
			throw illegal_argument();
		}
	}
	if (member(str1)){
		Trie_node *ptr = nullptr;
		if (root()->erase(str1,0, ptr)){
			trie_size= trie_size -1;
			return true;
		}	
	}
	return false;
}

void Trie::clear() {
	if(root()!= nullptr){
		root() -> clear();
		root_node = nullptr;	
	}
	trie_size = 0;
}

// You can modify this function however you want:  it will not be tested

std::ostream &operator<<( std::ostream &out, Trie const &trie ) {

	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
