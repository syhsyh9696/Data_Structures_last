#include <iostream>
#include "Matrix.h"

const int MAXINT = 32767;// Positive infinite
const int MAXNUM = 5;
int dist[MAXNUM];
int preva[MAXNUM];
    
using namespace std;

Matrix Dijkstra(Matrix temp, int v0) {
	int nodeNumber = temp.rows();
	bool* S = new bool[nodeNumber];

	for (int i = 0; i < nodeNumber; ++i) {
		dist[i] = temp[v0][i];
		S[i] = false;
		if (dist[i] == MAXINT)
			preva[i] = -1;
		else
			preva[i] = v0;
	}

	dist[v0] = 0;
	S[v0] = true;

	for (int i = 2; i < nodeNumber; ++i) {
		int mindist = MAXINT;
		int u = v0;
		for (int j = 1; j <= nodeNumber; ++j) {
			if ((!S[j]) && dist[j] < mindist) {
				u = j;
				mindist = dist[j];
			}

			S[u] = true;

			for (int j = 0; j < nodeNumber; ++j) {
				if ((!S[j]) && temp[u][j] < MAXINT) {
					if (dist[u] + temp[u][j] < dist[j]) {
						dist[j] = dist[u] + temp[u][j];
						preva[j] = u;
					}
				}
			}
		}

	}
	return temp;
}

int main(int argc, char const *argv[])
{
	Matrix test(4, 4);
	test[0][1] = 2;
	test[0][2] = 4;
	test[0][3] = 1;

	test[1][0] = 2;
	test[1][2] = 3;
	test[1][3] = 32767;

	test[2][0] = 4;
	test[2][1] = 3;
	test[2][3] = 6;

	test[3][0] = 1;
	test[3][1] = 32767;
	test[3][2] = 6;
	//int prev[MAXNUM];

	Dijkstra(test, 0);
	for (int i = 0; i < 4; ++i)
	{
		cout << "Length: " << dist[i] << endl;
	}
	//system("pause");

	
    return 0;
}
