#include <iostream>
using namespace std;
#define Max_N 45

int N;
int f[Max_N];

int main() {
    cin >> N;
    f[1] = 1;
    f[2] = 1;
    for(int i=3; i<N+1; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    cout << f[N];
}