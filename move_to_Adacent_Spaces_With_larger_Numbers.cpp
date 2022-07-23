#include <iostream>
using namespace std;

int Max_n = 100, n, x, y;

bool Isrange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int main() {
    cin >> n >> x >> y;
    x--; y--;
    int arr[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    int dx[4] = {-1, 1, 0, 0} , dy[4] = {0, 0, -1, 1};
    while(1) {
        int ischange = 0;
        cout << arr[x][y] << ' ';
        int max = arr[x][y];
        for(int i=0; i<4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(Isrange(nx, ny)) {
                if(arr[nx][ny] > max) {
                    ischange = 1;
                    x = nx;
                    y = ny;
                    break;
                }
            }
        }
        if(ischange == 0)
            return 0;
    }
}