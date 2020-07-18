// Graphs Breadth First Search

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

	//bfs
	void bfs(T src) {

		map<T, bool> visited;
		queue<T> q;

		q.push(src);
		visited[src] = true;

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			cout << node << " ";

			for (int nbr : l[node]) {
				//if the neighbour is not visited
				if (!visited[nbr]) {
					q.push(nbr);

					//mark that nbr as visited
					visited[nbr] = true;
				}
			}

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