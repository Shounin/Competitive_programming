/*https://ru.kattis.com/problems/logo*/

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

const double PI = atan(1)*4;
const double EPS = 1e-9;

complex<double> find_point(int heading, int distance){
    double x = cos(heading * PI / 180) * distance;
    double y = sin(heading * PI / 180) * distance;
    if(abs(y) < EPS) y = 0;
    if(abs(x) < EPS) x = 0;
    return complex<double>(x, y);
}

double dist(complex<double> a, complex<double> b){
    return sqrt(pow(a.real() - b.real(), 2) + pow(a.imag() - b.imag(), 2));
}

int main() {
    int t;
    cin >> t;

    for(int tc = 0; tc < t; tc++){
        int n;
        cin >> n;

        complex<double> start(0, 0);
        complex<double> cur = start;
        int heading = 180;
        for(int i = 0; i < n; i++){
            string s;
            int m;
            cin >> s >> m;

            switch(s[0]) {
                case 'f':
                    cur += find_point(heading, m);
                    break;
                case 'b':
                    if(heading < 180){
                        cur += find_point(360 - abs(heading - 180), m);
                    }
                    else{
                        cur += find_point(heading - 180, m);
                    }
                    break;
                case 'l':
                    heading -= m;
                    if(heading < 0){
                        heading = 360 - abs(heading);
                    }
                    break;
                case 'r':
                    heading = (heading + m) % 360;
                    break;
                default:
                    cout << "error";
                    break;
            }
        }

        cout << static_cast<int>(round(dist(cur, start))) << endl;
    }
    return 0;
}
