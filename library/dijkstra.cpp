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

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>>G(n);
    for(int i=0;i<m;i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        G[x].push_back({y, w});
    }

    // aizu online judgeでACは確認済み
    vector<bool>seen(n, false);
    vector<int>dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, s});
    while(!que.empty()){
        int d = que.top().fi;
        int v = que.top().se;
        que.pop();
        if(seen[v]){
            continue;
        }
        seen[v] = true;
        dist[v] = d;
        
        for(auto nv : G[v]){
            if(!seen[nv.fi]){
                que.push({d + nv.se, nv.fi});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
