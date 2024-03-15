
#include"Graph.h"
#include"Graph2.h"
#include"Graph3.h"
#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<string>
using namespace std;

int main() {

	fstream f("Country.txt", ios::in);
	string line;
	string v[500];
	int k = -1;
	if (f.is_open()) {
		f >> line;
		while (f)
		{
			k++;
			v[k] = line;
			//cout << line << endl;
			f >> line;
		}
	}
	f.close();

	int choice;

	do {
		cout << "0.Ford(Capacitate)" << endl << "1.TSP(Cost)" << endl << "2.Dijkstra(Distanta)" << endl << "3.Quit\n";
		cin >> choice;

		switch (choice)
		{
		case 0:
		{
			//O tara are la dispozitie vechicule cu diferite capacitati de transportare a marfurilor. Capacitatea vehiculelor
			//difera de la tara la tara. Aceasta problema ne arata capacitatea maxima care poate fi transportata intre 2 tari
			int x, y;
			for (int i = 0; i < k; i++)
				cout << i << ' ' << v[i] << endl;
			cout << "Dati tarile intre care are loc schimbul de marfuri:";
			cin >> x >> y;
			Graph g("Cantitate.txt");
			cout << "Capacitatea maxima care poate fi transportata intre : " << v[x] << " si " << v[y] << " este " << g.FordFulkerson(x, y) << "kg" << endl;
			break;
		}
		case 1:
		{
			//Avand o tara din care pleaca livrarea, o firma de transport marfuri are ca misiune livrarea de bunuri in toate
			//celelalte tari unde este posibila livrarea, apoi intoarcerea din punctul de pornire. Problema gaseste cea mai 
			//scurta(ieftina) ruta posibila(Modul de livrare, ruta stabilita de tari se iau in considerare).
			Graph2 g2("Cost.txt");
			int start;
			for (int i = 0; i < k; i++)
				cout << i << ' ' << v[i] << endl;
			cout << "Dati tara de unde porneste livrarea: ";
			cin >> start;
			pair<int, vector<int>> p = g2.TSP(start);
			int min_path_value = p.first;
			vector<int> path = p.second;

			cout << "Costul total:" << min_path_value << "$" << endl;
			cout << "drumul:" << v[start] << "-->";
			for (int i = 0; i < path.size(); i++)
				cout << v[path[i]] << "-->";
			cout << endl;
			break;
		}
		case 2:
		{
			//O firma de livrat marfuri are nevoie de distantele dintre tari, pentru a calcula cat combustibil este necesar
			//pentru livrare. Problema ne arata distanta dintre tara pe care o introducem si celelalte tari.
			Graph3 g("Distante.txt");
			int graph[30][30];
			int start;
			for (int i = 0; i < k; i++)
				cout << i << ' ' << v[i] << endl;
			cout << "Dati tara de unde se calculeaza distantele: ";
			cin >> start;
			g.dijkstra(graph, start);
			break;
		}
		case 3:
		{
			cout << "bye!";
			break;
		}

		}
	} while (choice != 3);

}
