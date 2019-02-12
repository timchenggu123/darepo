#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H

/****************************************
 * UW User ID:  uwuserid
 * Submitted for ECE 250
 * Semester of Submission:  (Winter|Spring|Fall) 20NN
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 ****************************************/

#include "Exception.h"
#include "ece250.h"

enum state { EMPTY, OCCUPIED, DELETED };

template<typename T>
class DoubleHashTable {
	private:
		int count;
		int power;
		int array_size;
		T *array;
		state *array_state;

		int h1( T const & ) const; // first hash function
		int h2( T const & ) const; // second hash function

	public:
		DoubleHashTable( int = 5 );
		~DoubleHashTable();
		int size() const;
		int capacity() const;		
		bool empty() const;
		bool member( T const & ) const;
		T bin( int ) const;

		void print() const;

		void insert( T const & );
		bool remove( T const & );
		void clear();
};

template<typename T >
DoubleHashTable<T >::DoubleHashTable( int m ):
count( 0 ), power( m ),
array_size( 1 << power ) ,//left shift
array( new T [array_size] ),
array_state( new state[array_size] ) {

	for ( int i = 0; i < array_size; ++i ) {
		array_state[i] = EMPTY;
	}
}

template<typename T >
DoubleHashTable<T >::~DoubleHashTable() {
	// enter your implemetation here 
}

template<typename T >
int DoubleHashTable<T >::size() const {
    // enter your implemetation here 
	return count;
}

template<typename T >
int DoubleHashTable<T >::capacity() const {
    // enter your implemetation here 
	return array_size;
}

template<typename T >
bool DoubleHashTable<T >::empty() const {
    // enter your implemetation here 
	if (count == 0){
		return true;
	}
	return false;
}

template<typename T >
int DoubleHashTable<T >::h1( T const &obj ) const {
	// enter your implemetation here 
	return 0;
}

template<typename T >
int DoubleHashTable<T >::h2( T const &obj ) const {
	// enter your implemetation here 
	return 0;
}

template<typename T >
bool DoubleHashTable<T >::member( T const &obj ) const {
	// enter your implemetation here 
	return false;
}

template<typename T >
T DoubleHashTable<T >::bin( int n ) const {
    // enter your implemetation here 	                      
	return T();
}

template<typename T >
void DoubleHashTable<T >::insert( T const &obj ) {
	 // enter your implemetation here 	
	 return ; 
}

template<typename T >
bool DoubleHashTable<T >::remove( T const &obj ) {
	 // enter your implemetation here 	
	return false;
}

template<typename T >
void DoubleHashTable<T >::clear() {
	 // enter your implemetation here 	
	 return ; 
}

//Print function won't be tested
template<typename T >
void DoubleHashTable<T >::print() const {
      // enter your implemetation here 	
	return;
}

#endif
