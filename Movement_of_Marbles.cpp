#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct s {
    int i;
    int v;

    s(int num, int vec) : i(num), v(vec) {}
};

struct cmp{
    bool operator()(s a, s b) {
        if(a.v == b.v) {
            return a.i > b.i;
        }
        return a.v > b.v;
    }
};

int m, n, t, k;
int dx[4] = {-1 , 0 , 0, 1},  dy[4] = {0, 1 , -1, 0};

bool isrange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int chartoint(char D) {
    if(D == 'U')
        return 0;
    else if (D == 'D')
        return 3;
    else if (D == 'R')
        return 1;
    else
        return 2;
}

int main() {
    cin >> n >> m >> t >> k;
    int marble[m][5];
    for(int i=0; i<m; i++) {
        for(int j=0; j<4; j++) {
            if(j == 2) {
                char t;
                cin >> t;
                int tt = chartoint(t);
                marble[i][j] = tt;
            }
            else 
                cin >> marble[i][j];
        }
        marble[i][4] = 1;
        marble[i][0]--;
        marble[i][1]--;
    }
    while(t--) {
        for(int i=0; i<m; i++) {
            for(int j=0; j<marble[i][3]; j++) {
                int nx = marble[i][0] + dx[marble[i][2]];
                int ny = marble[i][1] + dy[marble[i][2]];
                if(!isrange(nx, ny)) {
                    marble[i][2] = 3 - marble[i][2];
                    nx = marble[i][0] + dx[marble[i][2]];
                    ny = marble[i][1] + dy[marble[i][2]];
                }
                marble[i][0] = nx;
                marble[i][1] = ny;
            }
        }
        int table[n][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                table[i][j] = 0;
            }
        }
        for(int i=0; i<m; i++) {
            if(marble[i][4] == 1)
                table[marble[i][0]][marble[i][1]]++;
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(table[i][j] > k) {
                    priority_queue <s, vector<s>, cmp> pq;
                    int cnt = 0;
                    for(int i2=0; i2<m; i2++) {
                        if(marble[i2][4] == 1 && marble[i2][0] == i && marble[i2][1] == j) {
                            pq.push(s(i2, marble[i2][3]));
                            cnt++;
                        }
                    }
                    for(int i2=0; i2<cnt-k; i2++) {
                        s temp = pq.top();
                        marble[temp.i][4] = 0;
                        pq.pop();
                    }
                }
            }
        }
    }
    int count_marble = 0;
    for(int i=0; i<m; i++) {
        if(marble[i][4] == 1) 
            count_marble++;
    }
    cout << count_marble;
}