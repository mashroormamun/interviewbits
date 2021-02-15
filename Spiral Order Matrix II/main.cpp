#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

enum direction { RIGHT, DOWN, LEFT, UP };

vector<vector<int> > generateMatrix(int A) {
	vector<vector<int>> mat(A, vector<int>(A, 0));

	direction currentDirection = direction::RIGHT;

	int i = 0, j = 0;
	int count = 1;

	while (count <= (A * A)) {
		switch (currentDirection) {
		case direction::RIGHT:
			if ((j == A) || (mat[i][j] != 0)) {
				currentDirection = direction::DOWN;
				j--;
				i++;
				mat[i][j] = count++;
				i++;
			}
			else {
				mat[i][j++] = count++;
			}
			break;
		case direction::DOWN:
			if ((i == A) || (mat[i][j] != 0)) {
				currentDirection = direction::LEFT;
				j--;
				i--;
				mat[i][j] = count++;
				j--;
			}
			else {
				mat[i++][j] = count++;
			}
			break;
		case direction::LEFT:
			if ((j == -1) || (mat[i][j] != 0)) {
				currentDirection = direction::UP;
				j++;
				i--;
				mat[i][j] = count++;
				i--;
			}
			else {
				mat[i][j--] = count++;
			}
			break;
		case direction::UP:
			if ((j == -1) || (mat[i][j] != 0)) {
				currentDirection = direction::RIGHT;
				j++;
				i++;
				mat[i][j] = count++;
				j++;
			}
			else {
				mat[i--][j] = count++;
			}
			break;
		}
	}

	return mat;
}


int main()
{
	/*
	vector <vector<int>> B{
		{1,0,1},
		{1,1,1},
		{1,1,1},
	};*/
	
	vector <vector<int>>A = generateMatrix(4);

	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}