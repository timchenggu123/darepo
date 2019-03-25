#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <limits>
#include "Exception.h"
#include <queue>

/*****************************************
 * UW User ID:  uwuserid
 * Submitted for ECE 250
 * Semester of Submission:  (Winter|Spring|Fall) 20NN
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/
struct V
{
    double mKey;
    int mIndex;

    V(double key, int index) : mKey(key), mIndex(index)
    {
    }

    bool operator<(const struct V& other) const
    {
        //Your priority logic goes here
        return mKey > other.mKey;
    }
};

class Weighted_graph {
	private:
		static const double INF;
		double *weights;
		int size;
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

Weighted_graph::Weighted_graph(int n = 50):
weights(new double[n,n]),
size(n)
{
	//initializing the matrix to all infinity
	for (int i = 0; i < n; i ++){
		for (int j = 0; j< n; j++){
			weights[i,j] = INF;
		}
	}
	//initialzie vertices


}


int Weighted_graph::degree (int n) const{
	
}

int Weighted_graph::edge_count() const{};
double Weighted_graph::adjacent( int m, int n ) const{};

double Weighted_graph::minimum_spanning_tree( int n) const{
	std::priority_queue<V> Q;
	int member[size] = {};  //an array that holds whether a vertex is in Q. 0 is true 1 is false. 
	for (int i = 0; i < size; i++){
		if (i == n){
			//setting root vertex n to 0
			Q.push(V(0,i));
		} else{
			Q.push(V(INF,i));
		}
	}

	while(!Q.empty()){
		V u = Q.top();
		Q.pop;
		member[u.mIndex] = 1; 
		for(int i = 0; i< size; i++){
			if (adjacent(i,u.mIndex)){
				
			}
		}
	}
};
bool Weighted_graph::is_connected() const{};

void Weighted_graph::insert( int m, int n, double w ){};
// Enter definitions for all public functions here

std::ostream &operator << ( std::ostream &out, Weighted_graph const &graph ) {
	// Your implementation

	return out;
}



#endif
