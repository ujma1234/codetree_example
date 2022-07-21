#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;

    if(m == 1) {
        cout << 2*n;
        return 0;
    }

    int core=1;
    for(int i=0; i<n-1; i++) {
        if(arr[0][i] == arr[0][i+1]) {
            core++;
            if(core == m) {
                cnt++;
                break;
            }
            continue;
        }
        else {
            core = 1;
            continue;
        }
    }

    core=1;
    for(int i=0; i<n-1; i++) {
        if(arr[i][0] == arr[i+1][0]) {
            core++;
            if(core == m) {
                cnt++;
                break;
            }
            continue;
        }
        else {
            core = 1;
            continue;
        }
    }


    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(i == 0 && j == 0)
                continue;
            if(i != 0 && j != 0)
                continue;
            if(j == 0) {
                core=1;
                for(int k=j; k<n-1; k++) {
                    if(arr[i][k] == arr[i][k+1]) {
                        core++;
                        if(core == m) {
                            cnt++;
                            break;
                        }
                        continue;
                    }
                    else {
                        core = 1;
                        continue;
                    }
                }
            }
            if(i == 0) {
                core=1;
                for(int k=i; k<n-1; k++) {
                    if(arr[k][j] == arr[k+1][j]) {
                        core++;
                        if(core == m) {
                            cnt++;
                            break;
                        }
                        continue;
                    }
                    else {
                        core = 1;
                        continue;
                    }
                }
            }
        }
    }

    cout << cnt;
    return 0;
}