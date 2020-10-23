#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int MAXLEN = 10;

int map[MAXLEN][MAXLEN] = { 0 };
//int cost[MAXLEN][MAXLEN] = {0};

struct s152p_maze
{
    int yi;
    int xj;
    /* data */
}typedef node;


void bfs(int MAX_ny, int MAX_mx);

int main() {
    int n, m;

    cin >> n >> m;
    //cout << 'n'<<n << 'm'<<m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //cin >> map[i][j];//
            scanf("%1d", &map[i][j]);
        }
    }

    bfs(n, m);

    cout << map[n-1][m-1]-1;
    return 0;
}

void bfs(int MAX_ny, int MAX_mx) {
    int dx[] = { 0,0,1,-1 };
    int dy[] = { 1,-1,0,0 };
    int nx, ny;
    queue <node> q;
    node cur, next;
    cur.xj = 0;
    cur.yi = 0;
    q.push(cur);
    //int cost = 1;
    map[0][0] = 2;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        //cost++;
        for (int i = 0; i < 4; i++) {
            ny = dy[i] + cur.yi;
            nx = dx[i] + cur.xj;
            if (0 <= nx && nx < MAX_mx && 0 <= ny && ny < MAX_ny) {
                if (map[ny][nx] ==1) {
                    //
                    //cout << "D) ny:" << ny << "  nx:" << nx << endl;
                    //
                    //if (map[ny][nx] != 1 && map[ny][nx] > cost) {
                        map[ny][nx] = map[cur.yi][cur.xj]+1;
                    //}
                    
                    next.yi = ny;
                    next.xj = nx;

                    q.push(next);
                }

            }
        }
    }

}