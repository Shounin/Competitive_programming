/*https://ru.kattis.com/problems/peragrams*/

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
#include <complex>
using namespace std;

bool isOdd(int n){
    return (n % 2) == 1;
}

int main() {
    string s;
    cin >> s;
    int alpha[26];
    memset(alpha, 0, sizeof(alpha));

    int odd = 0;

    for (int i = 0; i < s.size(); ++i) {
        alpha[s[i] - 97]++;
    }

    for (int j = 0; j < 26; ++j) {
        if(alpha[j] != 0 && isOdd(alpha[j])){
            odd++;
        }
    }
    if(odd == 0){
        cout << 0;
    }
    else{
        cout << odd - 1;
    }
    return 0;
}
