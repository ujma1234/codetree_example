#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define max_n 100
#define max_m 100

int n, m;
int arr[max_n][max_m];
int ans[max_n][max_m];
int visited[max_n][max_m];
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, -1, 1};
queue<pair<int, int>> q;

void push(int x, int y) {
    ans[x][y] = 1;
    visited[x][y] = 1;
    q.push(make_pair(x, y));
}

bool inrange(int x, int y) {
    return (x>=0 && y>=0 && x<n && y<m);
}

bool cango(int x, int y) {
    return (inrange(x,y) && !visited[x][y] && arr[x][y]);
}

void BFS() {
    while(!q.empty()) {
        pair<int ,int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;
        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(cango(nx, ny)) {
                push(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
            ans[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    push(0,0);
    BFS();

    cout << ans[n-1][m-1];
}