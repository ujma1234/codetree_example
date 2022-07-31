#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define max_N 200
#define max_M 200

int N, M;
int size = 0;
int arr[max_N][max_M];
int visited[max_N][max_M];
int temp[max_N][max_M];
queue<pair<int, int>> q;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};

bool isrange(int x, int y) {
    return (x>=0 && y>=0 && x<N && y<M);
}

bool cango(int x, int y) {
    return (isrange(x,y) && !visited[x][y] && !arr[x][y]);
}

bool change_arr() {
    bool test = true;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            visited[i][j] = 0;
            if(temp[i][j] == 2) {
                temp[i][j] = 0;
            }
            arr[i][j] = temp[i][j];
            if(arr[i][j] == 1) 
                test = false;
        }
    }
    return test;
}

void push(int x, int y) {
    visited[x][y] = 1;
    temp[x][y] = 2;
    q.push(make_pair(x,y));
}

void BFS() {
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(cango(nx, ny)) {
                push(nx, ny);
            }
        }
    }
}

void melting() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(temp[i][j] == 2) {
                for(int ii=0; ii<4; ii++) {
                    int nx = i + dx[ii], ny = j + dy[ii];
                    if(isrange(nx, ny) && temp[nx][ny] == 1) {
                        temp[nx][ny] = 0;
                        size++;
                    }
                } 
            }
        }
    }
}


int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
            visited[i][j] = 0;
            temp[i][j] = arr[i][j];
        }
    }
    int cnt = 0;
    while(1) {
        size = 0;
        cnt++;
        push(0,0);
        BFS();
        melting();
        if(change_arr()) {
            break;
        }
    }
    cout << cnt << ' ' << size;
}