#include <iostream>
using namespace std;
#define max_N 100

int N;
int arr[max_N][max_N];
int ans[max_N][max_N];
int dx[2] = {0, -1} , dy[2] = {-1, 0};

bool isrange(int x, int y) {
    return (x>=0 && y>=0 && x<N && y<N);
}

void print_ans() {
    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<N; j++) {
    //         cout << ans[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << ans[N-1][N-1];
}

void init() {
    ans[0][0] = arr[0][0];
    for(int i=1; i<N; i++) {
        ans[i][0] = ans[i-1][0] + arr[i][0];
    }
    for(int i=1; i<N; i++) {
        ans[0][i] = ans[0][i-1] + arr[0][i];
    }
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
            ans[i][j] = -1;
        }
    }

    init();

    for(int i=1; i<N; i++) {
        for(int j=1; j<N; j++) {
            int max = 0;
            for(int k=0; k<2; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if(isrange(nx, ny)) {
                    if(ans[nx][ny] > max) {
                        max = ans[nx][ny];
                    }
                }
            }
            ans[i][j] = max + arr[i][j];
        }
    }

    print_ans();
}