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

#ifndef DYNAMIC_STACK_AS_ARRAY_H
#define DYNAMIC_STACK_AS_ARRAY_H

#ifndef nullptr
#define nullptr 0
#endif

#include <algorithm>
#include "Exception.h"

class Dynamic_range_stack {
	private:
		int entry_count;
		int max_count;
		int min_count;
		int initial_capacity;
		int current_capacity;

		int *stack_array;
		int *maximum_array;
		int *minimum_array;

		// You may wish to include a number of helper functions
		// in order to abstract out some operations


	public:
		Dynamic_range_stack( int = 10 );
		~Dynamic_range_stack();

		int top() const;
		int size() const;
		bool empty() const;
		int capacity() const;

		int maximum() const;
		int minimum() const;

		
		void push( int const & );
		int pop();
		void clear();


	// Friends

	friend std::ostream &operator<<( std::ostream &, Dynamic_range_stack const & );
};

Dynamic_range_stack::Dynamic_range_stack( int n ):
entry_count( 0 ),
min_count( 0 ),
max_count( 0 ),
initial_capacity( std::max( 1, n ) ),
current_capacity( initial_capacity ),
stack_array( new int[current_capacity] ),
maximum_array( new int[current_capacity] ),
minimum_array( new int[current_capacity] ) {
	// empty constructor
}

Dynamic_range_stack::~Dynamic_range_stack() {
	// Enter your implementation here.

}

int Dynamic_range_stack::top() const {
	// Enter your implementation here.
	int t = stack_array[entry_count-1];
	return t ;
}

int Dynamic_range_stack::maximum() const {
	// Enter your implementation here.
	int max = maximum_array[max_count-1];
	return max;
}

int Dynamic_range_stack::minimum() const {
	// Enter your implementation here.
	int min = minimum_array[min_count-1];
	return min;
}

int Dynamic_range_stack::size() const {
	// Enter your implementation here.
	return entry_count;
}

bool Dynamic_range_stack::empty() const {
	// Enter your implementation here.
	if (entry_count == 0){
		return 1;
	}else
	{
		return 0;
	}	
}

int Dynamic_range_stack::capacity() const {
	// Enter your implementation here.
	return current_capacity;
}



void Dynamic_range_stack::push( int const &obj ) {
	// Enter your implementation here.]
	//check if the current stack is full
	if (entry_count == current_capacity){
		
		int *new_array = new int[2*current_capacity];
		int *new_max_array = new int[2*current_capacity];
		int *new_min_array = new int[2*current_capacity];

		for (int i = 0; i < current_capacity; i++){
			new_array[i] = stack_array[i];
			new_max_array[i] = maximum_array[i];
			new_min_array[i] = minimum_array[i];
		}

		delete[] stack_array;
		delete[] maximum_array;
		delete[] minimum_array;

		stack_array = new_array;
		maximum_array = new_max_array;
		minimum_array = new_min_array;
		current_capacity = 2*current_capacity;
	}
	stack_array[entry_count] = obj;
	entry_count ++;
	//push to max stack

	int y = maximum();
	if (obj >= y){
		maximum_array[max_count] = obj;
	}else{
		maximum_array[max_count] = y;
	}
	max_count ++;

	 y = minimum();
	if (obj <= y){
		minimum_array[min_count] = obj;
	} else{
		minimum_array[min_count] = y;
	}
	min_count ++;
	return;
}

int Dynamic_range_stack::pop() {
	// Enter your implementation here.
	int t = top();
	entry_count --;
	max_count --;
	min_count --;
	return t;
}

void Dynamic_range_stack::clear() {
	// Enter your implementation here.
	if (initial_capacity != current_capacity){
		
		int *new_array = new int[initial_capacity];
		int *new_max_array = new int[initial_capacity];
		int *new_min_array = new int[initial_capacity];

		delete[] stack_array;
		delete[] maximum_array;
		delete[] minimum_array;
		
		stack_array = new_array;
		maximum_array = new_max_array;
		minimum_array = new_min_array;
		current_capacity = 2*current_capacity;
	}
}

// You can modify this function however you want:  it will not be tested

std::ostream &operator<<( std::ostream &out, Dynamic_range_stack const &stack ) {
	// Print out your stacks

	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
