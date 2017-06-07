/*https://ru.kattis.com/problems/snapperhard*/

#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d\n", &T);

    for(int tcs = 1; tcs <= T; tcs++){
        int n, k;
        scanf("%d %d", &n, &k);
        string output = "OFF";

        int bitMask = (1 << n) - 1;
        if(k % (1 << n) == bitMask){
            output = "ON";
        }

        printf("Case #%d: %s\n", tcs, output.c_str());
    }

    return 0;
}
