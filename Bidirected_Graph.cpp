#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int> > point;
vector<bool> visited;
int cnt=0;

void DFS(int vertex) {
    for(int i=0; i<point[vertex].size(); i++) {
        int curr_v = point[vertex][i];
        if(!visited[curr_v]) {
            cnt++;
            visited[curr_v] = true;
            DFS(curr_v);
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++)
        point.push_back(vector<int>());
    for(int i=0; i<N; i++)
        visited.push_back(false);
    for(int i=0; i<M; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tmp1--; tmp2--;
        point[tmp1].push_back(tmp2);
        point[tmp2].push_back(tmp1);
    }
    DFS(0);
    if(cnt<=1)
        cout << cnt;
    else 
        cout << cnt-1;
}