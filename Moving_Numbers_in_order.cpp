#include <iostream>
using namespace std;

int n,m;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool isrange(int x, int y) {
    return (x >= 0 && y >=0 && x<n && y<n);
}


int main() {
    cin >> n >> m;
    int arr[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    while(m--) {
        for(int i=1; i<n*n+1; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<n; k++) {
                    if(arr[j][k] == i) {
                        int max = 0;
                        int mx, my;
                        for(int i2=0; i2<8; i2++) {
                            int nx = j + dx[i2],  ny = k + dy[i2];
                            if(isrange(nx, ny)) {
                                if(arr[nx][ny] > max) {
                                    max = arr[nx][ny];
                                    mx = nx;
                                    my = ny;
                                }
                            }
                        }
                        int tmp = arr[j][k];
                        arr[j][k] = arr[mx][my];
                        arr[mx][my] = tmp;
                        j = j+100;
                        k = k + 100;
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}