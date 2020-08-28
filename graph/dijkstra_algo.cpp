// Dijkstra's Algorithm Shortest Path on Weighted Graphs

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph {
	unordered_map<T , list< pair<T, int> > > m;
public:

	void addEdge(T u, T v, int dist , bool bidir = true) {
		m[u].push_back(make_pair(v, dist));
		//if edges are birectional
		if (bidir) {
			m[v].push_back(make_pair(u, dist));
		}
	}


	void dijkstraSSSP(T src) {

		//make a map to store and update the distance
		unordered_map<T, int> dist;
		unordered_map<T, T> parent;

		//set all distance to infinity
		for (auto j : m) {
			dist[j.first] = INT_MAX;
		}

		//make a set to find out a node with the minimum distance
		set< pair<int, T> >s;

		dist[src] = 0;
		parent[src] = src;
		s.insert(make_pair(0, src)); //in set the sorting is based upon the first value , thats why we pair the distance first and then node

		while (!s.empty()) {

			//find the pair at the front
			//s.begin() gives the address of the first pair of the set and by '*' we deference it and it gives the actual pair now
			auto p = *(s.begin());
			//retrieve the name of the node
			T node = p.second;

			int nodeDist = p.first;
			s.erase(s.begin()); //src node pop out

			//iterate over neighbours/children of the current node
			for (auto childPair : m[node]) {
				//distance of parent node + distance of child node is lesser than the current distance of the child node , then update it
				if (nodeDist + childPair.second < dist[childPair.first]) {

					//update the child parent
					parent[childPair.first] = node;

					//in the set/pq updation of a particular is not possible
					//we have to remove the ols pair, and insert the new pair to simulation updation
					T dest = childPair.first;
					//find the child in the set
					auto f = s.find( make_pair(dist[dest], dest));

					if (f != s.end()) {
						//found the child in set
						//remove it from the set
						s.erase(f);
					}

					//insert the new pair
					dist[dest] = nodeDist + childPair.second;
					s.insert(make_pair(dist[dest], dest));
				}
			}

		}
		//lets print distance to all node from src
		for (auto d : dist) {
			cout << d.first << " is located at distance of " << d.second << endl;

			//print path
			cout << "path :-> ";
			T city = d.first;
			cout << city;
			while (city != src) {
				cout << " <-- " << parent[city] ;
				city = parent[city];
			}
			cout << endl << endl;
		}

	}


	//print the adjancey list
	void printAdj() {
		//iterate all the key value pairs in the map
		for (auto j : m) {
			cout << j.first << " :-> ";
			//iterate over the list
			for (auto l : j.second) {
				cout << " (" << l.first << "," << l.second << ") ,";
			}
			cout << endl;
		}
	}

};

int main(int argc, char const *argv[])
{

	// graph<int> g;

	// g.addEdge(1, 2, 1);
	// g.addEdge(1, 3, 4);
	// g.addEdge(2, 3, 1);
	// g.addEdge(3, 4, 2);
	// g.addEdge(1, 4, 7);

	// g.dijkstraSSSP(1);

	// cout << endl;

	// g.printAdj();



	graph<string> india;

	india.addEdge("AMRITSAR", "DELHI", 1);
	india.addEdge("AMRITSAR", "JAIPUR", 4);
	india.addEdge("JAIPUR", "DELHI", 2);
	india.addEdge("JAIPUR", "MUMBAI", 8);
	india.addEdge("BHOPAL", "AGRA", 2);
	india.addEdge("MUMBAI", "BHOPAL", 3);
	india.addEdge("AGRA", "DELHI", 1);

	india.dijkstraSSSP("AMRITSAR");

	cout << endl;

	india.printAdj();

	return 0;
}
