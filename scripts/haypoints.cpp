/*https://ru.kattis.com/problems/haypoints*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    string key;
    int value;
    map<string, int> dictionary;
    for(int i = 0; i < m; i++){
        cin >> key >> value;
        dictionary.insert(pair<string, int>(key, value));
    }
    for(int i = 0; i < n; i++){
        int sum = 0;
        string description;
        while(cin >> description){
            if(description == "."){
                break;
            }
            if(dictionary.count(description)){
                sum += dictionary.at(description);
            }
        }
        cout << sum << endl;
    }


    return 0;
}
