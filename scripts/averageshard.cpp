/*https://ru.kattis.com/problems/averageshard*/

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
vector<int> comp_iq;
vector<int> econ_iq;

void print(vector<int> vec){
    cout << "{ ";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << "}" << endl;
}

double avg(vector<int> vec){
    double sum = 0;
    for(int i = 0; i < vec.size(); i++){
        sum += vec[i];
    }
    return sum/vec.size();
}

int main() {
    int t;
    cin >> t;

    for(int tc = 0; tc < t; tc++){
        int cs = 0, ec = 0;
        cin >> cs >> ec;

        for(int i = 0; i < cs; i++){
            int iq;
            cin >> iq;
            comp_iq.push_back(iq);
        }
        for(int i = 0; i < ec; i++){
            int iq;
            cin >> iq;
            econ_iq.push_back(iq);
        }
        int count = 0;

        double comp_average = avg(comp_iq);
        if(econ_iq.size() == 0){
            for(int i = 0; i < comp_iq.size(); i++){
                if(comp_iq[i] < comp_average){
                    count++;
                }
            }
            cout << count << endl;
            continue;
        }
        double econ_average = avg(econ_iq);

        //print(comp_iq);
        //print(econ_iq);

        for(int i = 0; i < comp_iq.size(); i++){
            if(comp_iq[i] < comp_average && comp_iq[i] > econ_average){
                count++;
            }
        }

        cout << count << endl;
        comp_iq.clear();
        econ_iq.clear();
    }
    return 0;
}
