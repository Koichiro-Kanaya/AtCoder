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

    // Gの第一引数は頂点で第二引数が重みであることに注意．
    bool exist_negative_cycle = false;
    vector<int>dist(n, LINF);
    dist[s] = 0;
    for(int iter=0; iter<n; iter++){
        bool update = false;
        for(int i=0;i<n;i++){
            if(dist[i] == LINF){
                continue;
            }
            for(auto v : G[i]){
                if(chmin(dist[v.fi], dist[i] + v.se)){
                    update = true;
                }
            }
        }
        if(!update){
            break;
        }
        if(iter == n-1 && update){
            exist_negative_cycle = true;
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
