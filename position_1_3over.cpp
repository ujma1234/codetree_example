#include <iostream>
using namespace std;
bool InRange(int x, int y, int N) {
    return (0 <= x && x < N && 0 <= y && y < N);
}
int main () {
    int N;
    cin >> N;
    int arr[N][N];
    int total = 0;
    for (int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int cnt = 0;
            for(int k=0; k<4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if(InRange(nx, ny, N) && arr[nx][ny] == 1)
                    cnt++;
            }
            if(cnt >= 3)
                total++;
        }
    }

    cout << total;
}