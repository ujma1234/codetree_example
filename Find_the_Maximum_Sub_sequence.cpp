#include <iostream>
using namespace std;
#define max_int 1000
#define min_int -1000
#define max_n 100000

int n;
int arr[max_n];
int ans[max_n];
int answer = min_int;

void init() {
    ans[0] = arr[0];
    answer = ans[0];
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    init();
    for(int i=1; i<n; i++) {
        ans[i] = max(ans[i-1] + arr[i], arr[i]);
    }
    for(int i=1; i<n; i++) {
        if(ans[i] > answer)
            answer = ans[i];
    }
    cout << answer;
}