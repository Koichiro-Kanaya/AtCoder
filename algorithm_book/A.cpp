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

void dfs(Graph &G, vector<bool> &seen, vector<int> &toposo, int v){
    seen[v] = true;
    for(auto nv : G[v]){
        if(!seen[nv]){
            dfs(G, seen, toposo, nv);
        }
    }
    toposo.push_back(v);
}

// トポロジカルソートして，配るDPで解いた．
void solve() {
    int n,m;
    cin>>n>>m;
    Graph G(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--, y--;
        G[x].push_back(y);
    }

    vector<bool> seen(n, false);
    vector<int> toposo;
    for(int i=0;i<n;i++){
        if(!seen[i]){
            dfs(G, seen, toposo, i);
        }
    }

    reverse(toposo.begin(), toposo.end());
    vector<int>dp(n, -INF);
    for(int i=0;i<n;i++){
        if(dp[toposo[i]] == -INF){
            dp[toposo[i]] = 0;
        }
        for(auto nv : G[toposo[i]]){
            chmax(dp[nv], dp[toposo[i]] + 1);
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        chmax(ans, dp[i]);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
