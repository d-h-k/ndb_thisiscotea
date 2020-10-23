#include <iostream>
#include <cstring>
using namespace std;

int cost[1000];
int a;

int dfs(int now, int level) {
    return 0;
}

void dp(int tgt) {
    
    cost[tgt] = 0;
    for (int i = tgt; i >= 0; i--) {
        
        if (i % 5 == 0 ){
            if (cost[i / 5] > cost[i] + 1) {
                cost[i / 5] = cost[i] + 1;
            }
        }

        if (i % 3 == 0 ) {
            if (cost[i / 3] > cost[i] + 1) {
                cost[i / 3] = cost[i] + 1;
            }
        }


        if (i % 2 == 0 ) {
            if (cost[i / 2] > cost[i] + 1) {
                cost[i / 2] = cost[i] + 1;
            }
        }


        if (cost[i - 1 ] > cost[i] + 1) {
            cost[i-1] = cost[i] + 1;
        }
    }
}


int main() {
    
    cin >> a;

    cost[a] = 0;
    
    ///memset()
    //memset(cost, 1, sizeof(cost));
    //dfs(1, 0);
    for (int i = 0; i <= a; i++) {
        cost[i] = 2e8;
    }
    dp(a);
    
    cout << cost[1];


}