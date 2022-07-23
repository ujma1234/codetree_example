#include <iostream>
using namespace std;

int n, t;

int main() {
    cin >> n >> t;
    int up[n], down[n];
    for (int i=0; i<n; i++) {
        cin >> up[i];
    }
    for (int i=0; i<n; i++) {
        cin >> down[i];
    }

    for (int i=0; i<t; i++) {
        int tmp1 = up[n-1];
        for(int j=n-1; j != 0; j--) {
            up[j] = up[j-1];
        }
        int tmp2 = down[n-1];
        for(int k=n-1; k!=0; k--) {
            down[k] = down[k-1];
        }
        up[0] = tmp2;
        down[0] = tmp1;
    }

    for(int i=0; i<n; i++) {
        cout << up[i] << ' ';
    }
    cout << endl;
    for(int j=0; j<n; j++) {
        cout << down[j] << ' ';
    }
}