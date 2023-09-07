//============================================================================
// Name        : MatrixRotate.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
using namespace std;

void RotateRingOptimized(vector<vector<int>> matrix, int r) {
	int row = matrix.size() - 1;
	int column = matrix[0].size() - 1;
	int a = 0;
	//dummy and preserve matrix
	vector<vector<int>> matrixprint = matrix;
	//convert matrix to ring
	int maxRing = min(matrix.size() / 2, matrix[0].size() / 2);
	vector<vector<int>> ringForm;
	vector<int> ring;

	for (int i = 0; i < maxRing; ++i) {
		//top left (0+i,0+i)
		//top right (0+i, col-i)
		//bot left (row-i,0+i)
		//bot right (row-i, col-i)
		ring.clear();

		//top right to top left
		for (int j = column - i; j > i; --j) {
			ring.push_back(matrix[i][j]);
		}

		//top left to bot left
		for (int j = i; j < row - i; ++j) {
			ring.push_back(matrix[j][i]);
		}

		//bot left to bot right
		for (int j = i; j < column - i; ++j) {
			ring.push_back(matrix[row - i][j]);
		}
		//bot right to top right
		for (int j = row - i; j > i; --j) {
			ring.push_back(matrix[j][column - i]);
		}
		ringForm.push_back(ring);
	}

	int rotationRound[ringForm.size()] { 0 };

	for (int i = 0; i < ringForm.size(); ++i) {
		rotationRound[i] = r % ringForm[i].size();
	}

	for (int i = 0; i < ringForm.size(); ++i) {
		for (int j = 0; j < ringForm[i].size(); ++j) {
			cout << ringForm[i][j] << " ";
		}
		cout << endl;
	}
	//rotating ring new
	cout << "rotating ring" << endl;
	for (int i = 0; i < ringForm.size(); ++i) {
		for (int j = 0; j < rotationRound[i]; ++j) {
			a = ringForm[i][ringForm[i].size() - 1];
			for (int k = ringForm[i].size() - 1; k >= 0; --k) {
				if (k == 0) {
					ringForm[i][k] = a;
				} else {
					ringForm[i][k] = ringForm[i][k - 1];
				}
			}
		}
	}

	for (int i = 0; i < ringForm.size(); ++i) {
		for (int j = 0; j < ringForm[i].size(); ++j) {
			cout << ringForm[i][j] << " ";
		}
		cout << endl;
	}

	cout << "formatting output" << endl;
	//format output
	//re arrange ring to matrix and print
	for (int i = ringForm.size() - 1; i >= 0; --i) {
		//use matrixprint to do stuff
		//top right to top left
		for (int j = column - i; j > i; --j) {
			a = ringForm[i].front();
			matrixprint[i][j] = ringForm[i].front();
			ringForm[i].erase(ringForm[i].begin());

		}
		//top left to bot left
		for (int j = i; j < row - i; ++j) {
			a = ringForm[i].front();
			matrixprint[j][i] = ringForm[i].front();
			ringForm[i].erase(ringForm[i].begin());

		}
		//bot left to bot right
		for (int j = i; j < column - i; ++j) {
			a = ringForm[i].front();
			matrixprint[row - i][j] = ringForm[i].front();
			ringForm[i].erase(ringForm[i].begin());

		}
		//bot right to top right
		for (int j = row - i; j > i; --j) {
			a = ringForm[i].front();
			matrixprint[j][column - i] = ringForm[i].front();
			ringForm[i].erase(ringForm[i].begin());

		}
	}
	for (int i = 0; i < matrixprint.size(); ++i) {
		for (int j = 0; j < matrixprint[i].size(); ++j) {
			cout << matrixprint[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	vector<vector<int>> matrix;
	vector<int> row1 { 1, 2, 3, 4 };
	vector<int> row2 { 7, 8, 9, 10 };
	vector<int> row3 { 13, 14, 15, 16 };
	vector<int> row4 { 19, 20, 21, 22, };
	vector<int> row5 { 25, 26, 27, 28 };
	matrix.push_back(row1);
	cout << row4.front() << endl;
	matrix.push_back(row2);
	matrix.push_back(row3);
	matrix.push_back(row4);
	matrix.push_back(row5);
	RotateRingOptimized(matrix, 7);
	return 0;
}

