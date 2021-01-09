#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define int long long
#define fi first
#define se second
#define debug(x) cerr << #x << ": " << x << '\n' 

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int INF = 1001001001;
constexpr long long LINF = 1001001001001001001;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void bfs(Graph &G, vector<bool> &seen, int s){
    queue<int>que;
    que.push(s);
    seen[s] = true;
    while(!que.empty()){
        int v = que.front();
        que.pop();
        seen[v] = true;
        for(auto nv : G[v]){
            if(seen[nv] == false){
                que.push(nv);
            }
        }
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    Graph G(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int s,t;
    s--, t--;

    vector<bool> seen(n, false);
    bfs(G, seen, s);
    if(seen[t]) {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
