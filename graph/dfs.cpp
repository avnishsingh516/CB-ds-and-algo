// Depth First Search in Graphs


#include<iostream>
#include<map>
#include<queue>
#include <list>
using namespace std;

template<typename T>
class graph {

	map<T , list<T> > l;
public:

	//connect the vertices by edges
	void addEdge(int x, int y) {
		//assume the edges are bidirectional edges
		l[x].push_back(y);
		l[y].push_back(x);
	}

	//recursive function that will traverse the graph
	void dfs_helper(T src , map<T, bool> &visited) {
		//print the current or src node and mark it as visited
		cout << src << " ";
		visited[src] = true;

		//go to all nbr of that node that is not visited
		for (T nbr : l[src]) {
			if (!visited[nbr]) {
				//visit the nbr node
				dfs_helper(nbr, visited);
			}
		}

	}

	//dfs
	void dfs(T src) {

		map<T, bool> visited;

		//mark all the nodes as not visited in the begining
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}
		//call the helper function
		dfs_helper(src, visited);

		cout << endl;

	}

	//print
	void printAdjList() {
		//iterate over all the vertices
		for (auto p : l) {
			cout << "vertex " << p.first << " :- ";
			//iterate over the list of a particular vertex
			for (auto x : p.second) {
				cout << x << ",";
			}
			cout << endl;
		}
	}

};

int main(int argc, char const *argv[])
{

	graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	g.dfs(0);

	g.printAdjList();

	return 0;
}