#include <iostream>
using namespace std;

bool ratInMaze(char maze[10][10] , int soln[][10] , int i , int j , int m , int n) {
	//i -> curr row , j -> curr col
	//m -> row size , n -> col size

	//base case
	if (i == m and j == n) {
		soln[m][n] = 1;
		//print the path
		for (int i = 0 ; i <= m ; i++) {
			for (int j = 0 ; j <= n ; j++) {
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;

		return true;
		//return false , for multiple output;
	}

	//rat should be inside grid
	if (i > m or j > n) {
		return false;
	}

	//cell is blocked
	if (maze[i][j] == 'X') {
		return false;
	}

	//Assume sol exists through current cell
	soln[i][j] = 1;

	//check the ans from right
	bool rightSuccess = ratInMaze(maze, soln, i, j + 1, m, n);

	if (rightSuccess) {
		return true;
	}
	//check the ans from down
	bool downSuccess = ratInMaze(maze, soln, i + 1, j, m, n);

	if (downSuccess) {
		return true;
	}

	//backtracking
	soln[i][j] = 0;

	return false;

}

int main(int argc, char const *argv[])
{
	char maze[10][10] ;
	int m , n ;
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}
	int soln[10][10] = {0};


	cout << ratInMaze(maze, soln, 0, 0, m - 1, n - 1);

	return 0;
}