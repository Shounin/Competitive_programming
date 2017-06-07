/*https://ru.kattis.com/problems/gopher2*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;

struct flow_network {

    struct edge {
        int u, v, cap;
        edge *rev;
        bool forward;
        edge(int _u, int _v, int _cap, bool forw)
                : u(_u), v(_v), cap(_cap), forward(forw) { }
    };

    int n;
    vector<vector<edge*> > adj;
    flow_network(int _n) : n(_n), adj(_n) { }

    void add_edge(int u, int v, int cap) {
        edge *e = new edge(u, v, cap, true);
        edge *rev = new edge(v, u, 0, false);
        e->rev = rev;
        rev->rev = e;
        adj[u].push_back(e);
        adj[v].push_back(rev);
    }

    int augment(int s, int t) {
        vector<edge*> back(n, NULL);
        queue<int> Q;
        Q.push(s);
        back[s] = (edge*)1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i]->v;
                if (back[v] == NULL && adj[u][i]->cap > 0) {
                    back[v] = adj[u][i];
                    Q.push(v);
                }
            }
        }

        if (back[t] == NULL)
            return 0;

        stack<edge*> S;
        S.push(back[t]);
        int bneck = back[t]->cap;
        while (S.top()->u != s) {
            S.push(back[S.top()->u]);
            bneck = min(bneck, S.top()->cap);
        }

        while (!S.empty()) {
            S.top()->cap -= bneck;
            S.top()->rev->cap += bneck;
            S.pop();
        }

        return bneck;
    }

    int max_flow(int source, int sink) {
        int flow = 0;
        while (true) {
            int f = augment(source, sink);
            if (f == 0) {
                break;
            }

            flow += f;
        }

        return flow;
    }
};

double distTo(pair<double, double> g, pair<double, double> h){
    return sqrt(pow(g.first - h.first, 2) + pow(g.second - h.second, 2));
}

int main() {
    int n, m, s, v;
    while(scanf("%d %d %d %d", &n, &m, &s, &v) != -1){
        int SOURCE = 0,
            SINK = 1,
            LEFT = 2,
            RIGHT = LEFT + n,
            CNT = RIGHT + m;
        double max_dist = v * s;
        flow_network fn(CNT);

        vector<pair<double, double>> gophers;
        for(int i = 0; i < n; i++){
            double x, y;
            scanf("%lf %lf", &x, &y);
            gophers.push_back(make_pair(x, y));
        }

        vector<pair<double, double>> holes;
        for(int i = 0; i < m; i++){
            double x, y;
            scanf("%lf %lf", &x, &y);
            holes.push_back(make_pair(x, y));
        }

        for(int i = 0; i < gophers.size(); i++){
            for(int j = 0; j < holes.size(); j++){
                if(distTo(gophers[i], holes[j]) <= max_dist + EPS){
                    fn.add_edge(i + LEFT, j + RIGHT, 1);
                }
            }
        }

        for(int i = LEFT; i < RIGHT; i++){
            fn.add_edge(SOURCE, i, 1);
        }
        for(int i = RIGHT; i < CNT; i++){
            fn.add_edge(i, SINK, 1);
        }
        cout << n - fn.max_flow(SOURCE, SINK) << endl;
    }
    return 0;
}
