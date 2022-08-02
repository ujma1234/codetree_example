#include <iostream>
using namespace std;
#define max_N 1000

int N;
int arr[max_N];
int ans[max_N];

void init() {
    ans[0] = 1;
}

int find_max() {
    int tmp = ans[0];
    for(int i=1; i<N+1; i++) {
        tmp = max(tmp, ans[i-1]);
    }
    return tmp;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        ans[i] = 1;
    }

    for(int i=1; i<N; i++) {
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i]) {
                ans[i] = max(ans[j]+1, ans[i]);
            }
        }
    }

    cout << find_max();
}