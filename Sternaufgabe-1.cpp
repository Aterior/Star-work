//
// Created by Fabi on 22.10.2021.
//

#include <iostream>
#include <limits>

using namespace std;
// Ist das Unendlich
#define inf numeric_limits<int>::max()

int main() {
    // Vars für die erste Eingabe: n = Knoten, m = Kanten, r = r in Vorlesung
    int n, m, r;
    // Nimmt die Eingabe entgegen
    cin >> n >> m;
    // Da die Anzahl der Knoten auch r ist folgt dies Zuweisung.
    r = n;
    // graph ist die 2d Eingabematrix, u, v, w sind die Eingaben gemäß Anleitung Coderunner
    int u, v, w, dist[n][n];

    //T(n) = n^2
    //Initialisierung der 2d Matrix
    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            if(a == b){
                dist[a][b] = 0;
            } else {
                dist[a][b] = inf;
            }
        }
    }
    //T(n) = n
    //Input der Gewichte
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        dist[u - 1][v - 1] = w;
    }
    //T(n) = n^3
    // Der eigentliche Algo, Vars k,l,o random gewählt, Algo wie in Vorlesung
    for(int k = 0; k < r; k++){
        for(int l = 0; l < r; l++){
            for(int o = 0; o < r; o++){
                // Die Abfrage ist wichtig, da ansonsten inf überschrieben wird.
                if(dist[l][k] != inf && dist[k][o] != inf) {
                    if(dist[l][o] > (dist[l][k] + dist[k][o])){
                        dist[l][o] = dist[l][k] + dist[k][o];
                    }
                }
            }
        }
    }
    //T(n) = n^2
    //Printed die Ergebnismatrix
    for(int t = 0; t < r; t++){
        for(int z = 0; z < r; z++){
            if(dist[t][z] == inf){
                cout << "inf";
            } else {
                cout << dist[t][z];
            }
            if(z - (r-1) == 0){
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
}



/*
dist[l][o] != 9999999 &&
5 7
1 2 -9
1 5 2
2 1 12
2 4 3
3 5 -4
4 3 7
5 4 20

 for(int j = 0; j <= n-1; j++){
        for(int k = 0; k <= n-1; k++){
            cout << graph[j][k] << " ";
        }
        cout << endl;
    }

    numeric_limits<int>::max()

     int pos = 0;
    for(int i = 0; i <= m-1; i++){
        getline(cin, s, ' ');
        istringstream test;
        test.str(s);
        for (string temp; getline(test, temp, ' '); ){
            pos += temp.length() + 1;
            cout << pos << endl;
            cout << temp << endl;
            tempv.push_back(temp);
        }
        cout << "done" << endl;
        u = tempv[0];
        v = tempv[1];

        if((s.length() - pos) > 0){
            w = s.substr(pos, s.size());
        } else{
            w = "inf";
        }
        graph[stoi(u)-1][stoi(v)-1] = w;
    }

        /*
    //Ab hier beginnt der Warshall's Algo
    int dist[r][r]; // Das ist die Ausgabematrix
    // Der erste Teil des Algo's der hier nur eine Übergabe darstellt; Eigentlich unnötig
    for(int i = 0; i < r; i++){
        for(int j = 0; j < r; j++){
            dist[i][j] = graph[i][j];
        }
    }*/