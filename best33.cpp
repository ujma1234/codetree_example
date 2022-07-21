#include <iostream>
using namespace std;

int N;

int main() {
    cin >> N;
    int data[N][N];
    for(int i=0; i< N; i++) {
        for(int j=0; j<N; j++) {
            cin >> data[i][j];
        }
    }

    int Best_coin = 0;


    for(int i=0; i<N-2; i++) {
        for(int j=0; j<N-2; j++) {
            int coin = 0;
            for(int l=i; l<i+3; l++) {
                for(int m=j; m<j+3; m++) {
                    if(data[l][m] == 1)
                        coin++;
                    else
                        continue;
                }
            }
            if(Best_coin < coin)
                Best_coin = coin;
            else    
                continue;
        }
    }

    cout << Best_coin;
}