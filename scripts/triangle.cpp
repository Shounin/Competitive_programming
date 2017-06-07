/*https://ru.kattis.com/problems/triangle*/

#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;



int main() {
    int n;
    int tc = 1;
    while (cin >> n) {

        double circumference = 3.0;
        int output = -n * log10(2) + log10(circumference) + n * log10(3) + 1;
        printf("Case %d: %d\n", tc, output);
        tc++;
    }

    return 0;
}
