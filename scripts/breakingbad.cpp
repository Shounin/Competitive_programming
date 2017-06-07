/*https://ru.kattis.com/problems/breakingbad*/

#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> items;
vector<int> adj[100000];
vector<int> side(100000, -1);
vector<string> sides[2];
map<int, string> reversed_map;
bool is_bipartite = true;

void print(){
    int last;
    cout << "{ ";
    for(map<string, int>::iterator it = items.begin(); it != items.end(); it++){
        cout << it->first << " " << it->second << "|";
        last = it->second;
    }
    cout << " }" << endl;
    for(int i = 0; i <= last; i++){
        cout << i << ": {";
        for(int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << "}" << side[i] << endl;
    }
    for(map<int, string>::iterator it = reversed_map.begin(); it != reversed_map.end(); it++){
        cout << it->first << " " << it->second << "|";
    }
    cout << " }" << endl;
}

void output(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < sides[i].size(); j++){
            cout << sides[i][j] << " ";
        }
        cout << endl;
    }
}

void check_bipartite(int u){
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(side[v] == -1){
            side[v] = 1 - side[u];
            sides[side[v]].push_back(reversed_map[v]);
            check_bipartite(v);
        }
        else if(side[u] == side[v]){
            is_bipartite = false;
        }
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    string input_items;

    for(int i = 0; i < n; i++){
        cin >> input_items;
        items.insert(pair<string, int>(input_items, i));
    }

    for(map<string, int>::iterator it = items.begin(); it != items.end(); it++){
        reversed_map.insert(pair<int, string>(it->second, it->first));
    }
    scanf("%d", &m);
    string a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[items[a]].push_back(items[b]);
        adj[items[b]].push_back(items[a]);
    }

    for(int i = 0; i < n; i++){
        if(side[i] == -1){
            side[i] = 0;
            sides[side[i]].push_back(reversed_map[i]);
            check_bipartite(i);
        }
    }

    if(is_bipartite){
        output();
    }
    else{
        cout << "impossible";
    }

    //print();

    return 0;
}
