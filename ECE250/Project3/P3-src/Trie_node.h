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

#ifndef SINGLE_NODE_H
#define SINGLE_NODE_H

#ifndef nullptr
#define nullptr 0
#endif

#include <string>
#include <cctype>
#include "ece250.h"

class Trie;

class Trie_node
{
  private:
	Trie_node **children;
	bool is_terminal;
	static int const CHARACTERS = 26;
	int str2index(std::string &str);

  public:
	Trie_node();
	Trie_node *child(int) const;

	bool member(std::string const &, int) const;

	bool insert(std::string const &, int);
	bool erase(std::string const &, int, Trie_node *&);
	void clear();

	friend class Trie;

	// if ptr is a pointer to a Trie_node object
	// in one of the friendly classes, you should:
	//    use   ptr->next_   to modify it
	//    use   ptr->next()      to access it
};

Trie_node::Trie_node() : children(nullptr),
						 is_terminal(false)
{
	// empty constructor
}

Trie_node *Trie_node::child(int n) const
{
	if (children == nullptr)
	{
		return nullptr;
	}
	else
	{
		return children[n];
	}
}

bool Trie_node::member(std::string const &str, int depth) const
{

	if (depth == str.length())
	{
		return is_terminal;
	}
	int index = (int)str[depth];
	index = index - 65;
	if (child(index) != nullptr)
	{
		return child(index)->member(str, ++depth);
	}
	return false;
}

bool Trie_node::insert(std::string const &str, int depth)
{
	if (depth == str.length())
	{	
		if (is_terminal){
			return false;
		}
		this -> is_terminal = true;
		return true;
	}
	int index = (int)str[depth];
	index = index - 65;
	if (child(index) == nullptr)
	{
		if (children == nullptr)
		{
			children = new Trie_node *[CHARACTERS];
			for (int i = 0; i < 26; i++){
				children[i] = nullptr;
			}
		}
		children[index] = new Trie_node();
		return child(index)->insert(str, ++depth);
	}else
	{
		return child(index)->insert(str, ++depth);
	}
	
	return false;
}

bool Trie_node::erase(std::string const &str, int depth, Trie_node *&ptr_to_this)
{	bool branching_node = false;
	if (depth == str.length())
	{	
		if (is_terminal)
		{
			if (children == nullptr)
			{
				return false;

			}
			else
			{
				is_terminal = false;
				return true;
			}
		}
	}
	int index = (int)str[depth];
	index = index - 65;
	if (child(index) != nullptr)
	{
		int count = 0;
		for (int i = 0; i < 26; i++)
		{
			//check if there is a branch, if yet, save it and pass on
			if (children[i])
			{
				count = count + 1;
			}
			if (count > 1)
			{
				branching_node = true; //pointer to branching point;
			}
		}
		if (child(index)->erase(str, ++depth, ptr_to_this)){
			return true;
		}else
		{
			if(branching_node)	{
				child(index) -> clear();
				children[index] = nullptr;
				return true;
			}
			return false;
		}
		;
	}
	return false;
}

void Trie_node::clear()
{
	if (children != nullptr)
	{
		for (int i = 0; i < 26; i++)
		{
			if (children[i] != nullptr){
				children[i]->clear();
				delete children[i];
			}
		}
		delete[] children;
	}

}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
