#include <iostream>
#include <queue>
#include <cstdio>
#define MAXLEN 5
using namespace std;
int map[MAXLEN][MAXLEN] = { 1 };
int visited[MAXLEN][MAXLEN] = { 0 };
int xcol, yrow;
struct _node {
    int yi;
    int xj;
}typedef Node;

int bfs(Node start) {
    queue<Node> q;
    q.push(start);
    Node cur, next;
    int size = 0;

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        int dx[] = { 0,0,-1,1 };
        int dy[] = { -1,1,0,0 };
        int nx, ny;

        for (int i = 0; i < 4; i++) {
            nx = dx[i] + cur.xj;
            ny = dy[i] + cur.yi;

            if (0 <= nx && nx < xcol && 0 <= ny && ny < yrow) {
                if (map[ny][nx] == 0 && visited[ny][nx] == 0) {
                    size++;
                    visited[ny][nx] = 1;
                    next.yi = ny;
                    next.xj = nx;
                    q.push(next);
                }
            }
        }
    }
    return size;
}



bool dfs(int y, int x) {
    //if (x <= -1 or x >= n or y <= -1 or y >= m) {
    if (0<=x && x<xcol && 0<=y && y<yrow ) {
        return false;
    }else {}
     
    if (map[y][x] == 0) {
        map[y][x] = 1;
        dfs(y - 1, x);
        dfs(y + 1, x);
        dfs(y, x - 1);
        dfs(y, x + 1);
        return true;
    }else {
        return false;
    }
}

    


int main() {
    int cnt = 0;
    int area[555] = { 0 };
    Node temp;
    cin >> yrow >> xcol;
    for (int i = 0; i < yrow; i++) {
        for (int j = 0; j < xcol; j++) {
            //cin >> map[i][j];
            scanf("%1d", &map[i][j]);
        }
    }


    for (int i = 0; i < yrow; i++) {
        for (int j = 0; j < xcol; j++) {
            /*
            if (map[i][j] == 0 && visited[i][j] == 0) {
                temp.xj = j;
                temp.yi = i;
                visited[i][j] = 1;
                //puts("!!");
                area[cnt++] = bfs(temp);
            }*/

            if(dfs(i,j)  == true) {
                cnt++;
            }
        }
    }


    //print answer;
    cout << cnt << "answer";

}


//tc1
/*

4 5
00110
00011
11111
00000

*/



//tc2
/*

15 14
00000111100000
11111101111110
11011101101110
11011101100000
11011111111111
11011111111100
11000000011111
01111111111111
00000000011111
01111111111000
00011111111000
00000001111000
11111111110011
11100011111111
11100011111111


*/