// Single Source Shortest Path (sssp) using BFS Graphs

// Graphs Breadth First Search

#include<iostream>
#include<map>
#include<queue>
#include <list>
#include <climits>
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

	//sssp using bfs
	void bfs(T src) {

		map<T, int> dist;
		queue<T> q;

		//all other nodes will have int_max distance or dist
		for (auto node_pair : l) {
			T node = node_pair.first;
			dist[node] = INT_MAX;
		}

		//but src node have 0 dist
		dist[src] = 0;
		q.push(src);


		while (!q.empty()) {

			T node = q.front();
			q.pop();


			for (int nbr : l[node]) {
				//if the neighbour dist is INT_MAX
				//it means the node is visited first time
				if (dist[nbr] == INT_MAX) {
					q.push(nbr);

					//inc the dist by 1 from its prev node (dist[node])
					dist[nbr] = dist[node] + 1;
				}
			}

		}

		//print the dist to every node
		for (auto node_pair : l) {
			T node = node_pair.first;
			int d = dist[node];
			cout << "node " << node << " dist from src " << d << endl;
		}

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

	g.bfs(0);

	g.printAdjList();

	return 0;
}