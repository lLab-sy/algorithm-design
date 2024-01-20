#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define mkp(a, b) make_pair(a, b)

int n;
int A[101];

int bfs(int p){
    vector<bool> vis(n, false);

    queue<pii> q;
    q.push(mkp(p, 1));
    vis[p] = true;

    int cnt = 0;
    while(!q.empty()){
        int u = q.front().first;
        int d = q.front().second;
        q.pop();

        cnt++;
        for(int i=0;i<n;++i){
            if(!vis[i] and abs(A[i]-A[u]) <= d){
                vis[i] = true;
                q.push(mkp(i, d+1));
            }
        }
    }

    return cnt;
}

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    scanf("%d", &n);
    for(int i=0;i<n;++i) scanf("%d", &A[i]);

    int res = 0;
    for(int i=0;i<n;++i){
        res = max(res, bfs(i));
    }

    printf("%d", res);

    return 0;
}