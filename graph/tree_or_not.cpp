// Undirected Graph is a Tree or Not

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
	void addEdge(int x, int y) {
		//undirected graph
		l[x].push_back(y);
		l[y].push_back(x);
	}


	bool is_tree() {
		bool *visited = new bool[v];
		int *parent = new int[v];

		queue<int> q;

		//no node is visited in the begining . so, initialize all node visited = false
		for (int i = 0 ; i < v ; i++) {
			visited[i] = false;

			//in begin parent of each node is node itself
			parent[i] = i;
		}

		//starting node
		int src = 0;

		q.push(src);
		visited[src] = true;

		//pop out one node from the queue and visit its nbrs
		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (int nbr : l[node]) {
				//node is true means it was visited earlier and parent of node is not equal to its nbr
				//and cycle is present , return false
				if (visited[nbr] == true and parent[node] != nbr) {
					return false;
				}
				// node is not visited , the visit it and store its parent
				else if (!visited[nbr]) {
					visited[nbr] = true;
					parent[nbr] = node;
					q.push(nbr);
				}
			}
		}

		return true;

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

	graph g(4);

	g.addEdge(0, 1);
	g.addEdge(3, 2);
	g.addEdge(1, 2);
	g.addEdge(0, 3);

	//comment out the last edge for yes.. it is a tree

	if (g.is_tree()) {
		cout << "YES !! its a tree ..." << endl;
	}
	else {
		cout << "NO !! its not a tree ..." << endl;
	}

	cout << endl;
	g.printAdjList();

	return 0;
}