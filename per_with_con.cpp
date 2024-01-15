#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

void solve(int n, vector<int>& A, vector<bool>& pos, vector<int>& seq){
    if(!n){
        for(auto num: seq){
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0;i<seq.size()+n;++i){
        if(!pos[i] and (A[i] == -1 or pos[A[i]])){
            pos[i] = true;
            seq.push_back(i);
            solve(n-1, A, pos, seq);
            pos[i] = false;
            seq.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> A(n+1, -1);
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        A[b] = a;
    }

    vector<int> seq;
    vector<bool> pos(n+1, false);
    solve(n, A, pos, seq);

    return 0;
}