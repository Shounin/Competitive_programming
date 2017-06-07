/*https://ru.kattis.com/problems/dominoes2*/

#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m, l;
int sum;
vector<int> adj[10001];
vector<bool> visited(10001, false);

void dfs(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    sum++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs(v);
    }
}

void print(){
    for(int i = 1; i < n; i++){
        cout << i << ": ";
        for(int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}



int main() {
    int T;
    scanf("%d", &T);

    for(int tcs = 0; tcs < T; tcs++){
        sum = 0;
        scanf("%d %d %d", &n, &m, &l);
        n++;

        int a, b;
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            adj[a].push_back(b);
        }

        int tmp;
        for(int i = 0; i < l; i++){
            cin >> tmp;
            dfs(tmp);
        }

        //print();
        cout << sum << endl;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < adj[i].size(); j++){
                adj[i].clear();
            }
        }
        for(int i = 0; i < visited.size(); i++){
            visited[i] = false;
        }
    }


    return 0;
}
