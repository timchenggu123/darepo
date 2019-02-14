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
	delete[] array;
	delete[] array_state;
}

template<typename T >
int DoubleHashTable<T >::size() const {
	return count;
}

template<typename T >
int DoubleHashTable<T >::capacity() const {
	return array_size;
}

template<typename T >
bool DoubleHashTable<T >::empty() const {
	if (count == 0){
		return true;
	}
	return false;
}

template<typename T >
int DoubleHashTable<T >::h1( T const &obj ) const {
	int temp  = static_cast<int> (obj);
	temp = temp % array_size;
	if (temp < 0) {
		temp = temp + array_size;
	}

	return temp;
}

template<typename T >
int DoubleHashTable<T >::h2( T const &obj ) const {
	int temp = static_cast<int> (obj/array_size);
	temp = h1(temp);
	if ((temp % 2) == 0) {
		temp = temp + 1;
	}
	return temp;
}

template<typename T >
bool DoubleHashTable<T >::member( T const &obj ) const {
	if (empty() == true) {
		return false;
	}
	int h1_k = h1(obj);
	int h2_k = h2(obj);
	int i = 0;
	while (array_state[(h1_k + i * h2_k) % array_size] != EMPTY) {
		if (i == array_size) {
			break;
		}
		if (array_state[(h1_k + i * h2_k) % array_size] == DELETED) {
			i++;
			continue;
		}
		else if (array[(h1_k + i * h2_k) % array_size] != obj) {
			i++;
			continue;
		}
		return true;
	}
	return false;
}

template<typename T >
T DoubleHashTable<T >::bin( int n ) const {
    // enter your implemetation here 	
	T bin = array[n];
	return bin;
}

template<typename T >
void DoubleHashTable<T >::insert( T const &obj ) {
	if (count == array_size) {
		throw overflow();
	}
	int h1_k = h1(obj);
	int h2_k = h2(obj);
	int i = 0;
	while (array_state[(h1_k + i  * h2_k) % array_size] == OCCUPIED) {
		i++;
		if (i == array_size) {
			std::cout<<std::string("cannot insert")<<std::endl;
			return;
		}
	}

	array[(h1_k + i * h2_k) % array_size] = obj;
	array_state[(h1_k + i * h2_k) % array_size] = OCCUPIED;
	count++;

	 return ; 
}

template<typename T >
bool DoubleHashTable<T >::remove( T const &obj ) {
	if (empty() == true) {
		return false;
	 }
	int h1_k = h1(obj);
	int h2_k = h2(obj);
	int i = 0;
	while (array_state[(h1_k + i * h2_k) % array_size] != EMPTY) {
		if (i == array_size) {
			break;
		}
		if (array_state[(h1_k + i * h2_k) % array_size] == DELETED) {
			i++;
			continue;
		}
		else if (array[(h1_k + i * h2_k) % array_size] != obj) {
			i++;
			continue;
		}
		array_state[(h1_k + i * h2_k) % array_size] = DELETED;
		count = count - 1;
		return true;
	}
	return false;
}

template<typename T >
void DoubleHashTable<T >::clear() {
	for (int i = 0; i < array_size; i++) {
		array_state[i] == EMPTY;
	 }
	 count = 0;
	 return ; 
}

//Print function won't be tested
template<typename T >
void DoubleHashTable<T >::print() const {
      for (int i = 0; i < array_size; i ++){
		  std::cout << array_state[i] << std::endl;
	  }
		return;
}

#endif
