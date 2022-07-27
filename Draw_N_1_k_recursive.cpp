#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> answer;

void Print() {
    for(int i=0; i<answer.size(); i++)
        cout << answer[i]+1 << ' ';
    cout << endl;
}

void choose(int crr_num) {
    if(crr_num == N+1){
        Print();
        return;
    }
    for(int i=0; i<K; i++) {
        answer.push_back(i);
        choose(crr_num+1);
        answer.pop_back();
    }
    return;

}

int main() {
    cin >> K >> N;
    choose(1);
    return 0;
}