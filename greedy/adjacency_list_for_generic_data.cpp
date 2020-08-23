// Graphs Adjacency List Implementation for Generic Data
// using the hash map instead of array of list

#include<iostream>
#include <unordered_map>
#include <list>
#include <cstring>
using namespace std;

class graph {
	//adj list
	unordered_map< string , list< pair<string, int> > >l;

public:
	//add edges , bidir:- bidirectional and wt:- weight
	void addEdge(string x , string y , bool bidir , int wt) {

		l[x].push_back(make_pair(y, wt));

		//if it is birectional edge
		if (bidir) {
			//y is also connected to x vertex with same edge
			l[y].push_back(make_pair(x, wt));
		}
	}

	//print
	void printAdjList() {
		//iterate over all the keys or vertex in the map
		for (auto p : l) {
			string city = p.first;

			//pair
			list<pair<string, int> > nbrs = p.second;

			cout << city << " :- ";
			//iterate every pair
			for (auto nbr : nbrs) {
				string dest = nbr.first; //destination city
				int dist = nbr.second; //distance

				cout << dest << " " << dist << ", ";
			}

			cout << endl;
		}
	}

};

int main(int argc, char const *argv[])
{

	graph g;

	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D", true, 40);
	g.addEdge("A", "C", true, 10);
	g.addEdge("C", "D", true, 40);
	g.addEdge("A", "D", false, 50);

	g.printAdjList();

	return 0;
}