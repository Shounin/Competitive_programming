/*https://ru.kattis.com/problems/billiard*/


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

const double PI = atan(1)*4;

int main() {
    int a, b, s, n, m;
    while(scanf("%d %d %d %d %d", &a, &b, &s, &n, &m) != -1){
        if(a == 0 && b == 0 && s == 0 && n == 0 && m == 0){
            break;
        }
        double A = atan(((static_cast<double>(b)/2.0)/static_cast<double>(n))/((static_cast<double>(a)/2.0)/static_cast<double>(m)));
        double distance = (a*n) / (cos(A));
        printf("%.2lf %.2lf\n", A * (180/PI), distance / s);
    }

    return 0;
}
