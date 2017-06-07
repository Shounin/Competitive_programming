/* https://ru.kattis.com/problems/bank */

#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> customers;
    bool marked[47];
    memset(marked, 0, sizeof(marked));

    int x, y;

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        customers.push_back(pair<int, int>(x, y));
    }

    sort(customers.rbegin(), customers.rend());
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(!marked[customers[i].second]){
            marked[customers[i].second] = true;
            sum += customers[i].first;
        }
        else{
            for(int j = customers[i].second - 1; j >= 0; j--){
                if(!marked[j]){
                    marked[j] = true;
                    sum += customers[i].first;
                    break;
                }
            }
        }
    }

    cout << sum;
    return 0;
}
