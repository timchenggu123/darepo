#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <limits>
#include "Exception.h"
#include <queue>
#include <vector>
#include <algorithm>

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
    double *mKey;
    int mIndex;

    V(double key, int index) : mKey(&key), mIndex(index)
    {
    }

    bool operator<(const struct V& other) const
    {
        //Your priority logic goes here
        return *mKey > *other.mKey;
    }
};

class Custom_Priority_Queue{
	private:
		std::vector<V> mVertices;
		int mSize;
		void heapify(int);
	public:
		Custom_Priority_Queue();
		void push(V vertex);
		void pop();
		V top();
		void update();
		bool empty();
};
Custom_Priority_Queue::Custom_Priority_Queue():
	mSize(0){}

void Custom_Priority_Queue::heapify(int index){
	if (2*index > mSize -1){
		return;
	}
	if (2*index + 1 > mSize -1){
		if (*mVertices[2*index].mKey + 1 > *mVertices[index].mKey){
			V temp = mVertices[index];
			mVertices[index] = mVertices[2*index];
			mVertices[2*index] = temp;
		}
		return;
	}
	if (*mVertices[index].mKey < *mVertices[2*index].mKey){
		if (*mVertices[2*index].mKey < *mVertices[2*index + 1].mKey){
			V temp = mVertices[index];
			mVertices[index] = mVertices[2*index +1];
			mVertices[2*index+ 1] = temp;
		}else{
			V temp = mVertices[index];
			mVertices[index] = mVertices[2*index];
			mVertices[2*index] = temp;
		}
	}else if (*mVertices[index].mKey < *mVertices[2*index + 1].mKey){
		V temp = mVertices[index];
		mVertices[index] = mVertices[2*index +1];
		mVertices[2*index+ 1] = temp;
	}
	heapify(2*index);
	heapify(2*index + 1);
}

void Custom_Priority_Queue::push(V vertex){
	mVertices.push_back(vertex);
	mSize ++;
	int i = mSize;
	while (i/2 >= 0){
		if (*mVertices[i].mKey > *mVertices[i/2].mKey){
			V temp = mVertices[i];
			mVertices[i] = mVertices[i/2];
			mVertices[i/2] = temp;
		}else{
			break;
		}
	}
}

V Custom_Priority_Queue::top(){
	return mVertices[0];
}

void Custom_Priority_Queue::pop(){
	V temp = mVertices[0];
	mVertices[0] = mVertices[mVertices.size()-1];
	mVertices[mVertices.size() -1 ] = temp;
	mVertices.pop_back();
	heapify(0);
	mSize --;
}

void Custom_Priority_Queue::update(){
	heapify(0);
}

bool Custom_Priority_Queue::empty(){
	if (mSize == 0){
		return true;
	}else{
		return false;
	}
}

class Weighted_graph {
	private:
		static const double INF;
		double *weights;
		double *keys;
		int *v_degree;
		int edgeCount;
		int mSize;
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
keys(new double[n]),
v_degree(new int[n]),
edgeCount(0),
mSize(n)
{
	//initializing the matrix to all infinity
	for (int i = 0; i < n; i ++){
		keys[i] = INF;
		v_degree[i] = 0;
		for (int j = 0; j< n; j++){
			weights[i,j] = INF;
		}
	}

}


int Weighted_graph::degree (int n) const{
	if (n > mSize-1 || n < 0){
		throw illegal_argument();
	}
	return v_degree[n];
}

int Weighted_graph::edge_count() const{

}

double Weighted_graph::adjacent( int m, int n ) const{
	if (m > mSize-1 || n > mSize-1 || m <0 || n < 0){
		throw illegal_argument();
	}
	if(m == n){
		return 0;
	}
	return weights[m,n];
};

double Weighted_graph::minimum_spanning_tree( int n) const{
	if ( n > mSize-1 ||  n < 0){
		throw illegal_argument();
	}
	int MST_size = 0;

	Custom_Priority_Queue Q;
	int T_member[mSize] = {};  //an array that holds whether a vertex is in Q. 0 is true 1 is false. 
	Q.push(V(0,n));
	keys[n] = 0;
	while(!Q.empty()){
		V u = Q.top();
		Q.pop;
		T_member[u.mIndex] = 1; 
		MST_size = MST_size + *u.mKey;
		for(int v = 0; v< mSize; v++){
			if (adjacent(v,u.mIndex) != INF){
				if(!T_member[v] && adjacent(v,u.mIndex) < keys[v]){
					if (keys[v] == INF){
						keys[v] = adjacent(v,u.mIndex);
						Q.push(V(keys[v],v));
					}else{
						keys[v] = adjacent(v,u.mIndex);
						Q.update();
					}
				}
			}
		}
	}
};
bool Weighted_graph::is_connected() const{
	int n =0;
	int nNodes = 0;

	std::priority_queue<V> Q;
	int member[mSize] = {};  //an array that holds whether a vertex is in Q. 0 is true 1 is false. 
	Q.push(V(0,n));
	keys[n] = 0;
	while(!Q.empty()){
		V u = Q.top();
		Q.pop;
		member[u.mIndex] = 1; 
		nNodes ++;
		for(int v = 0; v< mSize; v++){
			if (adjacent(v,u.mIndex) != INF){
				if(!member[v] && adjacent(v,u.mIndex) < keys[v]){
					keys[v] = adjacent(v,u.mIndex);
					Q.push(V(adjacent(v,u.mIndex),v));
				}
			}
		
		}
	}
	if (nNodes == mSize){
		return true;
	}else{
		return false;
	}
};

void Weighted_graph::insert( int m, int n, double w ){
	if (m > mSize-1 || n > mSize-1 || m <0 || n < 0){
		throw illegal_argument();
	}
	if (w < 0 || w == INF){
		throw illegal_argument();
	}
	if (w == 0){
		if (weights[m,n] != INF){
			v_degree[n] --;
			v_degree[m] --;
			edgeCount --;
		}
		weights[m,n] = INF;
		weights[n,m] = INF;
		return;
	}
	if (weights[m,n] == INF){
		v_degree[n] ++;
		v_degree[m] ++;
		edgeCount ++;
	}
	weights[m,n] = w;
	weights[n,m] = w;
	//degree ++
	//set edges for mn & nm.
};
// Enter definitions for all public functions here

std::ostream &operator << ( std::ostream &out, Weighted_graph const &graph ) {
	// Your implementation

	return out;
}



#endif
