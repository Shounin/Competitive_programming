/*https://ru.kattis.com/problems/doorman*/

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

int main() {
    int n;
    string s;

    cin >> n;
    cin >> s;
    queue<char> q;
    for(int i = 0; i < s.length(); i++){
        q.push(s[i]);
    }
    pair<char, bool> tmp;
    tmp.second = false;

    int count_women = 0;
    int count_men = 0;

    while(!q.empty()){
        if(tmp.second){
            switch(tmp.first){
                case 'W':
                    if(!((count_women - count_men) + 1 > n)){
                        tmp.second = false;
                        count_women++;
                    }
                    break;
                case 'M':
                    if(!((count_men - count_women) + 1 > n)){
                        tmp.second = false;
                        count_men++;
                    }
                    break;
            }
        }
        switch(q.front()){
            case 'W':
                if((count_women - count_men) + 1 > n){
                    if(!tmp.second) {
                        tmp.first = q.front();
                        tmp.second = true;
                        q.pop();
                        break;
                    }
                    else if(tmp.second && tmp.first == 'M'){
                        count_men++;
                        tmp.second = false;
                        break;
                    }
                    else{
                        cout << count_men + count_women;
                        return 0;
                    }
                }
                else{
                    count_women++;
                    q.pop();
                    break;
                }
            case 'M':
                if((count_men - count_women) + 1 > n){
                    if(!tmp.second) {
                        tmp.first = q.front();
                        tmp.second = true;
                        q.pop();
                        break;
                    }
                    else if(tmp.second && tmp.first == 'W'){
                        count_women++;
                        tmp.second = false;
                        break;
                    }
                    else{
                        cout << count_men + count_women;
                        return 0;
                    }
                }
                else{
                    count_men++;
                    q.pop();
                    break;
                }
        }
    }
    cout << count_men + count_women;
    return 0;
}
