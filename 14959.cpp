#include <iostream>
#include <queue>

using namespace std;

int cost[100000];
bool check[100000];
int mini,maxi;
int su,dong,ans=99999999;

int bfs(int start){
    queue<int> q;
    q.push(start);

    int cur, next;
    while(!q.empty() ) {
        cur = q.front();
        q.pop();
        if(cost[cur+1] == 0 && check[cur+1] == false) {
            q.push(cur+1);
            check[cur+1] = true;
        }

        if(cost[cur-1] == 0 && check[cur-1] == false) {
            q.push(cur-1);
            check[cur-1] = true;
        }
        
        if(cost[cur*2] == 0 && check[cur*2] == false) {
            q.push(cur-1);
            check[cur*2] == true;
        }
        
    }
}


int dfs(int now, int dep) {
    if(dong == now) {
        if(ans>dep) {
            ans = dep;
        }
        return 0;
    }
    else if(mini< now && now <maxi) {
        dfs(now+1,dep+1);
        dfs(now-1,dep+1);
        dfs(now*2,dep+1);
    }
    else {
        return 0;
    }
    
    return 0;
}


int main() {
    

    cin >> su >> dong;

    if(su>dong){
        maxi = su;
        mini = dong;
    }
    else {
        maxi = dong;
        mini = su;
    }

    //dfs(su,0);
    //bfs(su);
    cout << ans;
    return 0;
}