// Cycle Detection in UnDirected Graph using DFS

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


	bool cycle_helper(int node , bool *visited , int parent) {
		// parent stores the parent node of the current node

		//mark that node visited
		visited[node] = true;

		for (int nbr : l[node]) {
			//two cases

			// 1. nbr is not visited
			if (!visited[nbr]) {
				//go and visit the neighbour recursively
				// and parent of that nbr is node
				bool cycle_mila = cycle_helper(nbr , visited , node);

				if (cycle_mila) {
					//cycle is founded by the nbr in the graph
					return true;
				}

			}
			//2. nbr is visited but nbr should not be the parent of that node
			//it means it contains the cycle
			else if (nbr != parent) {
				return true;
			}
		}

		//cycle is not found yet
		return false;

	}

	//chexk for cycle in directed graph
	bool contains_cycle() {

		bool *visited = new bool[v];

		//initialize all visited and stack array node by false
		for (int i = 0 ; i < v ; i++) {
			visited[i] = false;
		}

		return cycle_helper( 0 , visited , -1);
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

	graph g(5);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 0);

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