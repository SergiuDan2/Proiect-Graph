#pragma once
#include <iostream>
#include<fstream>
#include<string>
using namespace std;
#include <limits.h>

#define Ve 25

class Graph3 {
    int V;
    int** adjMat;
public:
    Graph3(string fis) {
        ifstream is(fis);
        is >> V;
        adjMat = new int* [V];
        for (int i = 0; i < V; i++)
            adjMat[i] = new int[V];
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                is >> adjMat[i][j];

    }

    int minDistance(int dist[], bool sptSet[])
    {

        int min = INT_MAX, min_index;

        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;

        return min_index;
    }

    void printSolution(int dist[])
    {
        fstream f("tari.txt", ios::in);
        string line;
        string p[500];
        int k = -1;
        if (f.is_open()) {
            f >> line;
            while (f)
            {
                k++;
                p[k] = line;
                //cout << line << endl;
                f >> line;
            }
        }
        f.close();
        cout << "Tara \t Distanta de la tara" << endl;
        for (int i = 0; i < V; i++)
            cout << p[i] << " \t\t" << dist[i] << "km" << endl;
    }

    void dijkstra(int graph[30][30], int src)
    {
        int dist[Ve];

        bool sptSet[Ve];


        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;


        dist[src] = 0;

        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                graph[i][j] = adjMat[i][j];


        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;
            for (int v = 0; v < V; v++)
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
        }

        printSolution(dist);
    }
};

