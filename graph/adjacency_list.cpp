// Graphs Adjacency List Implementation


#include <iostream>
#include <list>
using namespace std;

class Graph {
	int v; //vertex
	list<int> *l; //array of list

public:
	Graph(int v) {
		this->v = v;
		l = new list<int>[v];
	}

	//connect the vertices by edges
	void addEdge(int x, int y) {
		//assume the edges are bidirectional edges
		l[x].push_back(y);
		l[y].push_back(x);
	}

	//print
	void printAdjList() {
		//iterate over all the vertices
		for (int i = 0 ; i < v ; i++) {
			cout << "vertex " << i << " :- ";
			//iterate over the list of a particular vertex
			for (int x : l[i]) {
				cout << x << ",";
			}
			cout << endl;
		}
	}

};

int main(int argc, char const *argv[])
{

	//create a graph with 4 vertices
	Graph g(4);

	//add edges
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 2);

	g.printAdjList();

	return 0;
}