/*https://ru.kattis.com/problems/freckles*/

#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

const double EPS = 1e-9;


struct union_find {
    vector<int> parent;
    union_find(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};


struct edge {
    int u, v;
    double weight;
    edge(int _u, int _v, double _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

bool edge_cmp(const edge &a, const edge &b) {
    return a.weight < b.weight - EPS;
}
vector<edge> mst(int n, vector<edge> edges) {
    union_find uf(n);
    sort(edges.begin(), edges.end(), edge_cmp);
    vector<edge> res;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u,
                v = edges[i].v;
        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            res.push_back(edges[i]);
        }
    }
    return res;
}

void print(vector<edge> a){
    cout << "Vector: {";
    for(int i = 0; i < a.size(); i++){
        printf("%d %d %f |", a[i].u, a[i].v, a[i].weight);
    }
    cout << " }" << endl;
}

void print(vector<pair<double, double>> a){
    cout << "Vector: {";
    for(int i = 0; i < a.size(); i++){
        printf("%f %f |", a[i].first, a[i].second);
    }
    cout << " }" << endl;
}

double distTo(pair<double, double> pointA, pair<double, double> pointB){
    double dist = sqrt(pow(pointA.first - pointB.first, 2) + pow(pointA.second - pointB.second, 2));
    if(dist < 0){
        return -dist;
    }
    else{
        return dist;
    }
}

int main() {
    int T;
    scanf("%d\n", &T);
    for(int tcs = 0; tcs < T; tcs++){
        int n;
        scanf("%d", &n);
        double sum = 0.0;
        vector<pair<double, double>> points;
        vector<edge> edges;

        double x, y;
        for(int i = 0; i < n; i++){
            scanf("%lf %lf", &x, &y);
            points.push_back(pair<double, double>(x, y));
        }


        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                edges.push_back(edge(i, j, distTo(points[i], points[j])));
            }
        }


        vector<edge> minimum_tree = mst(n, edges);

        for(int i = 0; i < minimum_tree.size(); i++){
            sum += minimum_tree[i].weight;
        }

        printf("%.2lf\n\n", sum);
    }


    return 0;
}
