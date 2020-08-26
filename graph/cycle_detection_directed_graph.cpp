// Cycle Detection in Directed Graph using DFS

#include<iostream>
#include<queue>
#include <list>
using namespace std;


class graph {

	list<int> *l;
	int v;

public:
	graph(int v) {
		this->v = v;
		l = new list<int>[v];
	}

	//connect the vertices by edges
	void addEdge(int x, int y , bool directed = true) {
		//directed graph
		l[x].push_back(y);

		if (!directed) {
			//undirected graph
			l[y].push_back(x);
		}
	}


	bool cycle_helper(int node , bool *visited , bool *stack) {
		//mark that node visited
		visited[node] = true;

		//node is also the part of the current path
		stack[node] = true;

		for (int nbr : l[node]) {
			//two cases

			//1. back edge :- if the nbr is the part of current path , it means it contains cycle
			if (stack[nbr] == true) {
				return true;
			}
			//2. check that the did nbr get a cycle or not and it was not visited earlier
			else if (!visited[nbr]) {
				// by rec call , check whether its nbr get cycle or not
				bool cycle_mila = cycle_helper(nbr , visited , stack);

				if (cycle_mila == true) {
					//they found cycle
					return true;
				}
			}
		}


		// while leaving the node , now the node is not part of the current path
		stack[node] = false;

		//cycle is not found yet
		return false;

	}

	//chexk for cycle in directed graph
	bool contains_cycle() {

		bool *visited = new bool[v];
		//an array of name stack
		bool *stack = new bool[v];

		//initialize all visited and stack array node by false
		for (int i = 0 ; i < v ; i++) {
			visited[i] = stack[i] = false;
		}

		return cycle_helper( 0 , visited , stack);
	}


	//print
	void printAdjList() {
		//iterate over all the vertices
		for (int i = 0 ; i < v ; i++) {
			cout << "vertex " << i << " :- ";
			//iterate over the list of a particular vertex
			for (auto x : l[i]) {
				cout << x << ",";
			}
			cout << endl;
		}
	}

};

int main(int argc, char const *argv[])
{

	graph g(7);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(1, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 2); //back edge

	//comment out the last edge for no.. it is a cyclic graph

	if (g.contains_cycle()) {
		cout << "YES !! the graph contain cycle ..." << endl;
	}
	else {
		cout << "NO !! the graph cant contain cycle ..." << endl;
	}

	cout << endl;

	g.printAdjList();

	return 0;
}