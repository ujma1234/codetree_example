#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    int jen[n];
    for(int i=0; i<n; i++) {
        cin >> jen[i];
    }
    int rm[4];
    for(int i=0; i<4; i++)
        cin >> rm[i];
    int t, e;
    for(int i=0; i<4; i+=2) {
        int tmp[n] = {0,};
        t = 0;
        e = 0;
        for(int j=0; j<n; j++) {
            if(j < rm[i]-1 || j > rm[i+1]-1) {
                tmp[t] = jen[j];
                t++;
                if(jen[j] != 0)
                    e++;
            }
        }
        for(int j=0; j<n; j++) {
            if(tmp[j] != 0) {
                jen[j] = tmp[j];
            }
            else {
                jen[j] = 0;
            }
        }
    }
    cout << e << endl;
    for(int i=0; i <n; i++) {
        if(jen[i] != 0)
            cout << jen[i] << endl;
    }
}