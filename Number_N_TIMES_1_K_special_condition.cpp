#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> answer;

void Print() {
    for(int i=0; i<answer.size(); i++) {
        cout << answer[i]+1 << ' ';
    }
    cout << endl;
}

void choose(int cur) {
    if(cur == N+1) {
        Print();
        return;
    }
    
    for(int i=0; i<K; i++) {
        if(cur <= 2 || (answer[answer.size()-2] != answer[answer.size()-1] || answer[answer.size()-1] != i)) {
            answer.push_back(i);
            choose(cur+1);
            answer.pop_back();
        }

    }
    return;
}

int main() {
    cin >> K >> N;
    choose(1);
    return 0;

}