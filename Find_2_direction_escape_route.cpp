#include <iostream>
using namespace std;
#define max_n 100
#define max_m 100

int n,m;
int arr[max_n][max_m];
int visited[max_n][max_m];
int answer[max_n][max_m];
int dx[2] = {1,0}, dy[2] = {0,1};

bool inrange(int x, int y) {
    return (x>=0 && y>=0 && x<n && x<m);
}

bool cango(int x, int y) {
    return (inrange(x,y) && visited[x][y] == 0 && arr[x][y] == 1);
}

void DFS(int x, int y) {
    for(int i=0; i<2; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(cango(nx, ny)) {
            visited[nx][ny] = 1;
            answer[nx][ny] = 1;
            DFS(nx, ny);
        } 
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
            visited[i][j] = 0;
            answer[i][j]= 0;
        }
    }
    answer[0][0] = 1;
    visited[0][0] = 1;
    DFS(0,0);
    if(answer[n-1][m-1] == 1)
        cout << 1;
    else
        cout << 0;
}