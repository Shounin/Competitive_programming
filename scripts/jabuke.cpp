/*https://ru.kattis.com/problems/jabuke*/


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

const double EPS = 1e-9;

double area(complex<double> triangle[]){
    return abs((abs((triangle[0].real() * (triangle[1].imag() - triangle[2].imag()))
            + (triangle[1].real() * (triangle[2].imag() - triangle[0].imag()))
            + (triangle[2].real() * (triangle[0].imag() - triangle[1].imag())))) / 2);
}

void print(complex<double> stuffz[]){
    cout << "{";
    for(int i = 0; i < 3; i++){
        cout << stuffz[i].real() << " " << stuffz[i].imag() << "| ";
    }
    cout << "}" << endl;
}

int main() {
    int n;
    complex<double> triangle[3];
    vector<complex<double>> trees;

    for(int i = 0; i < 3; i++){
        double x, y;
        scanf("%lf %lf", &x, &y);
        triangle[i].real(x);
        triangle[i].imag(y);
    }
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        double x, y;
        scanf("%lf %lf", &x, &y);
        trees.push_back(complex<double>(x, y));
    }
    double TriangleArea = area(triangle);

    complex<double> tmpTri[3];
    int count = 0;

    for(int i = 0; i < trees.size(); i++){
        double treeArea = 0;
        tmpTri[0] = trees[i];
        //cout << "#: " << i << endl;
        for(int j = 0; j < 3; j++){
            tmpTri[1] = triangle[j];
            tmpTri[2] = triangle[(j + 1) % 3];
            //print(tmpTri);
            treeArea += area(tmpTri);
            //cout << treeArea << endl;
        }
        //cout << "total:" << treeArea << endl;
        if(abs(treeArea - TriangleArea) < EPS){
            count++;
        }
    }

    printf("%.1lf\n%d", TriangleArea, count);
    return 0;
}
