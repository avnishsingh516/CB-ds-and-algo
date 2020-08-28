// Snakes and Ladder BFS-SSSP Problem Graphs

#include<bits/stdc++.h>
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
		//the edges are unidirectional edges
		l[x].push_back(y);
	}

	//sssp using bfs
	int bfs(T src , T dest) {

		map<T, int> dist;
		map<T, T> parent; //track the path
		queue<T> q;

		//all other nodes will have int_max distance or dist
		for (auto node_pair : l) {
			T node = node_pair.first;
			dist[node] = INT_MAX;
		}

		//but src node have 0 dist
		dist[src] = 0;
		q.push(src);
		parent[src] = src; // parent of src is src itself

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
					parent[nbr] = node; //stores its parent node

				}
			}

		}

		//print the path form dest to src
		T temp = dest;
		while (temp != src) {
			cout << temp << "<--";
			temp = parent[temp];
		}
		cout << src << endl;

		//print the min dice throw from src to dest node
		cout << "min times dice thrown to reach the destinaton or win :- " << dist[dest] << endl << endl;

		//to see the every node parent
		// for (int i = 0 ; i <= 36 ; i++) {
		// 	cout << i << " :- " << parent[i] << endl;
		// }
	}



};

int main(int argc, char const *argv[])
{
	//input
	int board[50] = {0};

	//snakes and ladder
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;

	//add edges to the graph

	graph<int> g;

	for (int i = 0 ; i < 36 ; i++) {
		for (int dice = 1 ; dice <= 6 ; dice++) {
			int j = i + dice;
			j += board[j];

			if (j <= 36) {
				//edges are unidirectional
				g.addEdge(i, j);
			}

		}
	}

	//add last edge
	g.addEdge(36, 36);

	//src , destination
	g.bfs(0, 36);

	return 0;
}