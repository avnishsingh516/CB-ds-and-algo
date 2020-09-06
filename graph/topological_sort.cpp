// DAG's Topological Sort Using DFS Graphs
//graph is unidirectional and non cyclic

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
	void addEdge(T x, T y) {
		//assume the edges are unidirectional edges
		l[x].push_back(y);
		// l[y].push_back(x);
	}

	//recursive function that will traverse the graph
	void dfs_helper(T src , map<T, bool> &visited , list<T> &ordering) {
		//print the current or src node and mark it as visited
		// cout << src << " ";
		visited[src] = true;

		//go to all nbr of that node that is not visited
		for (T nbr : l[src]) {
			if (!visited[nbr]) {
				//visit the nbr node
				dfs_helper(nbr, visited, ordering);
			}
		}

		//at this point before returing
		ordering.push_front(src);

		return;

	}

	//dfs
	void dfs() {

		map<T, bool> visited;
		list<T> ordering; //stores the ordering

		//mark all the nodes as not visited in the begining
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}

		//iterate over all the vertices and initiate a dfs call , if the node is not visited
		for (auto p : l) {
			T node = p.first;

			if (!visited[node]) {
				//node is not visited
				//call the helper function
				dfs_helper(node, visited, ordering);

			}

		}

		//finally print the list
		cout << " ordering :-> " << endl;
		for (auto node : ordering) {
			cout << node << endl;
		}


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

	graph<string> g;

	g.addEdge("PYTHON", "DATA PRE PROCESSING");
	g.addEdge("PYTHON", "PYTORCH");
	g.addEdge("PYTHON", "ML");
	g.addEdge("DATA PRE PROCESSING", "ML");
	g.addEdge("PYTORCH", "DL");
	g.addEdge("ML", "DL");
	g.addEdge("DL", "FACE RECOGN");
	g.addEdge("DATA SET", "FACE RECOGN");

	g.dfs();

	cout << endl << endl << "graph look :-> " << endl << endl;
	g.printAdjList();

	return 0;
}