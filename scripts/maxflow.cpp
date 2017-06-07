/*https://ru.kattis.com/problems/maxflow*/

#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

using namespace std;



struct flow_network {

    int n;
    struct edge {
        int u, v, cap;
        edge *rev;
        bool forward;
        edge(int _u, int _v, int _cap, bool forw)
                : u(_u), v(_v), cap(_cap), forward(forw) { }
    };

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

struct tripair{
    int u, v, c;
    tripair(int _u, int _v, int _c){
        u = _u;
        v = _v;
        c = _c;
    }
};

int main() {
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    flow_network fn(n);

    for(int i = 0; i < m; i++){
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        fn.add_edge(u, v, c);
    }
    vector<tripair> output;
    int flow = fn.max_flow(s, t);

    for(int i = 0; i < fn.adj.size(); i++){
        for(int j = 0; j < fn.adj[i].size(); j++){
            if(fn.adj[i][j]->forward && fn.adj[i][j]->rev->cap != 0){
                output.push_back(tripair(fn.adj[i][j]->u, fn.adj[i][j]->v, fn.adj[i][j]->rev->cap));
            }
        }
    }

    cout << n << " " << flow << " " << output.size() << endl;
    for(int i = 0; i < output.size(); i++){
        cout << output[i].u << " " << output[i].v << " " << output[i].c << endl;
    }


    return 0;
}
