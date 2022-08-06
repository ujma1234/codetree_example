#include <iostream>
using namespace std;
#define max_N 100
#define max_M 10000
#define max_coin 10000

int N, M;
int coin[max_N];
int dp[max_M];

void init() {
    for(int i=0; i<M+1; i++) {
        dp[i] = 10001;
    }

    dp[0] = 0;
}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> coin[i];
    }
    init();
    for(int i=0; i<M+1; i++) {
        for(int j=0; j<N; j++) {
            if(i - coin[j] >= 0) {
                if(i == coin[j]) {
                    dp[i] = 1;
                }
                else {
                    dp[i] = min(dp[i-coin[j]]+1, dp[i]);
                }
            }
        }
    }
    if(dp[M] == max_coin+1)
        cout << -1;
    else
        cout << dp[M];
}