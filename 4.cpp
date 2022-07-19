#include <iostream>
using namespace std;
int n, m;
bool InRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

int main() {
    cin >> n >> m;
    int ans[n][m] = {0,};
    int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
    int x=0, y=0;
    int dir_num = 0;
    ans[x][y] = 1;
    for(int i=2; i<=n*n; i++) {
        int nx = x + dx[dir_num], ny = y + dy[dir_num];

        if(!InRange(nx, ny) || ans[nx][ny])
            dir_num = (dir_num + 1) % 4;
        
        x = x + dx[dir_num]; y = y+dy[dir_num];
        ans[x][y] = i;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}