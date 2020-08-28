// Topological Sort Using BFS Graphs


#include<iostream>
#include<map>
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
	void addEdge(int x, int y) {
		//directed graph
		l[x].push_back(y);
	}


	void topological_sort() {

		//indegree
		int *indegree = new int[v];
		//initialize all vetices with 0 indgree
		for (int i = 0 ; i < v; i++) {
			indegree[i] = 0;
		}

		//update indegree by traversing edges x->y
		//indegree[y]++

		for (int i = 0 ; i < v ; i++) {
			for (auto y : l[i]) {
				indegree[y]++;
			}
		}

		//bfs
		queue<int> q;
		//1. step find nodes with 0 indegree
		for (int i = 0; i < v ; i++) {
			if (indegree[i] == 0) {
				// push the node in queue
				q.push(i);
			}
		}

		//2. start removing elements from the queue
		while (!q.empty()) {
			int node = q.front();

			//topology order
			cout << node << " ";
			q.pop();

			//iterate over nbrs of that node and reduce their indegree by 1
			for (auto nbr : l[node]) {
				indegree[nbr]--;
				//indegree of node become 0 then push it in queue
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
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

	graph g(6);

	g.addEdge(0, 2);
	g.addEdge(1, 4);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 5);
	g.addEdge(3, 5);
	g.addEdge(4, 5);

	g.topological_sort();

	cout << endl;
	g.printAdjList();

	return 0;
}