/* https://ru.kattis.com/problems/bachetsgame */

#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool positions[1000001];

vector<int> moves;

bool isNposition(int x){
    for(int i = 0; i < moves.size(); i++){
        if(moves[i] > x) break;
        if(positions[x - moves[i]]) return true;
    }
    return false;
}


int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        memset(positions, 0, sizeof(positions));

        int tmp;
        for (int i = 0; i < m; i++) {
            cin >> tmp;
            moves.push_back(tmp);
        }

        sort(moves.begin(), moves.end());

        positions[0] = true;

        for (int i = 1; i <= n; i++) {
            if (!isNposition(i)) {
                positions[i] = true;
            }
        }

        if (!positions[n]) {
            cout << "Stan wins" << endl;
        }
        else {
            cout << "Ollie wins" << endl;
        }

        moves.clear();

    }
    return 0;
}
