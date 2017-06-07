/*https://ru.kattis.com/problems/getshorty*/

#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include<queue>

using namespace std;

double EPS = 1e-9;

struct edge {
    int u, v;
    double weight;
    edge(int _u, int _v, double _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

vector<edge> adj[10000];
vector<double> dist(10000, -1);

void dijkstra(int start) {
    dist[start] = 1.0;
    priority_queue<pair<double, int>,
            vector<pair<double, int> >,
            less<pair<double, double> > > pq;
    pq.push(make_pair(dist[start], start));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v;
            double w = adj[u][i].weight;
            if (w * dist[u] - EPS > dist[v]) {
                dist[v] = w * dist[u];
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void print(int n){
    cout << "adj: { ";
    for(int i = 0; i < n; i++){
        cout << "[ ";
        for(int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j].weight << " ";
        }
        cout << "]";
    }
    cout << "}" << endl;
}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != -1 && (n != 0 && m != 0)){
        for(int i = 0; i < m; i++){
            int x, y;
            double w;
            scanf("%d %d %lf", &x, &y, &w);
            adj[x].push_back(edge(x, y, w));
            adj[y].push_back(edge(y, x, w));
        }

        //print(n);

        dijkstra(0);
        double output = dist[n - 1];
        printf("%.4lf\n", output);

        for(int i = 0; i < n; i++){
            adj[i].clear();
            dist[i] = -1;
        }
    }
    return 0;
}
