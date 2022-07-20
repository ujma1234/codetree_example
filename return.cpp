#include <iostream>
using namespace std;

int N;

int char_to_num(char D) {
    if(D == 'N')
        return 3;
    else if (D == 'S')
        return 1;
    else if (D == 'W')
        return 2;
    else 
        return 0;
}

int main() {
    cin >> N;
    char dir[N];
    int dis[N];
    for(int i=0; i<N; i++)
        cin >> dir[i] >> dis[i];
    int x=0, y=0, cnt = 0;
    dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

    for(int i=0; )
}