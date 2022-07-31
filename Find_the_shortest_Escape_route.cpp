#include <iostream>
#include <queue>
#include <utility>
#define max_n 100
#define max_m 100
using namespace std;

int n, m;
int arr[max_n][max_m];
int visited[max_n][max_m];
int answer[max_n][max_m];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};
queue<pair<int, int>> q;

void push(int x, int y, int s) {
    visited[x][y] = 1;
    answer[x][y] = s+1;
    q.push(make_pair(x, y));
}

bool isrange(int x, int y) {
    return (x>=0 && y>=0 && x<n && y<m);
}

bool cango(int x, int y) {
    return (isrange(x, y) && !visited[x][y] && arr[x][y]);
}

void BFS() {
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;
        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            int s = answer[x][y];
            if(cango(nx, ny)) {
                push(nx, ny, s);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
            visited[i][j] = 0;
            answer[i][j] = -1;
        }
    }
    push(0,0,-1);
    BFS();
    cout << answer[n-1][m-1];
}