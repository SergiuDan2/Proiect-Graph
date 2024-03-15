
#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<string>
using namespace std;
class Graph2 {
	int V;
	int** adjMat;
public:
	Graph2(string fis) {
		ifstream is(fis);
		is >> V;
		adjMat = new int* [V];
		for (int i = 0; i < V; i++)
			adjMat[i] = new int[V];
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				is >> adjMat[i][j];

	}
	pair<int, vector<int>> TSP(int start) {

		vector<int> vertex;
		// lista nodurilor in afara de nodul de start
		for (int i = 0; i < V; i++)
			if (i != start)
				vertex.push_back(i);
		// initializam valoarea minima a drumului cu INT_MAx
		pair<int, vector<int>> path;
		int min_path = INT_MAX;
		do {
			int curr_path_weight = 0;
			int k = start;
			for (int i = 0; i < V - 1; i++) {
				curr_path_weight += adjMat[k][vertex[i]];
				k = vertex[i];
			}
			if (curr_path_weight < min_path) {
				min_path = curr_path_weight;
				path = make_pair(min_path, vertex);
			}

		} while (next_permutation(vertex.begin(), vertex.end()));
		return path;
	}
};

