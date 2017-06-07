/*https://ru.kattis.com/problems/virus*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef string::iterator strIt;

int main(){
        string healthy, infected;
        cin >> healthy >> infected;

        if(healthy == infected){
            cout << 0;
            return 0;
        }

        strIt healthyFront = healthy.begin();
        strIt healthyBack = healthy.end() - 1;


        strIt infectedFront = infected.begin();
        strIt infectedBack = infected.end() - 1;


        while(true){
            if(healthyFront == healthyBack || infectedFront == infectedBack){
                healthyFront--;
                infectedFront--;
                break;
            }
            if(*healthyFront == *infectedFront){
                healthyFront++;
                infectedFront++;
            }
            else{
                healthyFront--;
                infectedFront--;
                break;
            }
        }

        while(true){
            if(healthyBack == healthyFront || infectedBack == infectedFront){
                healthyBack++;
                infectedBack++;
                break;
            }
            if(*healthyBack == *infectedBack){
                healthyBack--;
                infectedBack--;
            }
            else{
                healthyFront--;
                infectedFront--;
                break;
            }
        }

        cout << infectedBack - infectedFront - 1 << endl;
    return 0;
}
