#pragma once
#include<fstream>
#include<iostream>
#include<queue>
using namespace std;
class Graph {
	int V;
	int** graph;
public:
	Graph(string fis) {
		ifstream is(fis);
		is >> V;
		graph = new int* [V];
		for (int i = 0; i < V; i++)
			graph[i] = new int[V];
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				is >> graph[i][j];

	}
	bool BFS(int** rGraph, int s, int t, int* parent) {
		bool* visited = new bool[V];
		for (int i = 0; i < V; i++)
			visited[i] = false;
		queue<int> q;

		q.push(s);
		visited[s] = true;
		parent[s] = -1;

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v = 0; v < V; v++)
				if (!visited[v] && rGraph[u][v] > 0) {
					if (v == t) {
						parent[v] = u;
						return true;
					}
					q.push(v);
					visited[v] = true;
					parent[v] = u;

				}
		}
		return false;

	}
	int FordFulkerson(int s, int t) {
		int u, v;
		int** rGraph = new int* [V];
		for (int i = 0; i < V; i++)
			rGraph[i] = new int[V];
		int** fGraph = new int* [V];
		for (int i = 0; i < V; i++)
			fGraph[i] = new int[V];

		int maxFlow = 0;
		int* parent = new int[V];


		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++) {
				rGraph[i][j] = graph[i][j];
				fGraph[i][j] = 0;
			}

		while (BFS(rGraph, s, t, parent)) {
			int pathFlow = INT_MAX;

			for (v = t; v != s; v = parent[v]) {
				u = parent[v];
				pathFlow = min(pathFlow, rGraph[u][v]);
			}

			for (v = t; v != s; v = parent[v]) {
				u = parent[v];
				rGraph[u][v] -= pathFlow;
				rGraph[v][u] += pathFlow;
				fGraph[u][v] += pathFlow;
			}
			maxFlow += pathFlow;
		}
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++)
				cout << fGraph[i][j] << "  ";
			cout << endl;
		}

		return maxFlow;
	}

};

