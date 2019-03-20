#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <limits>
#include "Exception.h"

/*****************************************
 * UW User ID:  uwuserid
 * Submitted for ECE 250
 * Semester of Submission:  (Winter|Spring|Fall) 20NN
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/

class Weighted_graph {
	private:
		static const double INF;
		// your choice

	public:
		Weighted_graph( int = 50 );
		~Weighted_graph();

		int degree( int ) const;
		int edge_count() const;
		double adjacent( int, int ) const;
		double minimum_spanning_tree( int ) const;
		bool is_connected() const;

		void insert( int, int, double );

	// Friends

	friend std::ostream &operator << ( std::ostream &, Weighted_graph const & );
};

const double Weighted_graph::INF = std::numeric_limits<double>::infinity();

// Enter definitions for all public functions here

std::ostream &operator << ( std::ostream &out, Weighted_graph const &graph ) {
	// Your implementation

	return out;
}



#endif
