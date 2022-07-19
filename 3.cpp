#include <iostream>
using namespace std;

bool InRange(int x, int y, int n) {
    return (1 <= x && x <= n && 1 <= y && y <= n);
}

int diretion(char D) {
    if(D == 'U')
        return 2;
    else if (D == 'D')
        return 1;
    else if (D == 'R')
        return 0;
    else 
        return 3;
}

int main() {
    int N, t;
    cin >> N;
    cin >> t;
    int x, y; char d;
    cin >> x; cin >> y; cin >> d;
    int dx[4] = {0,1,-1,0}, dy[4] = {1, 0, 0, -1};
    int dir_num = diretion(d);
    for(int i=0; i<t; i++) {
        x += dx[dir_num], y += dy[dir_num];
        if(!InRange(x,y,N)){
            x -= dx[dir_num], y -= dy[dir_num];
            dir_num = 3 - dir_num;
        }
    }
    cout << x << ' ' << y;
}