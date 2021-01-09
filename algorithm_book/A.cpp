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

bool ng = false;

void dfs(Graph &G, vector<int> &color, int v){
    for(auto next_v : G[v]){
        if(color[next_v] == -1){
            color[next_v] = 1 - color[v];
            dfs(G, color, next_v);
        }
        else if(color[next_v] == color[v]){
            ng = true;
        }
        else{
            continue;
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

    vector<int> color(n, -1);
    color[0] = 0;
    dfs(G, color, 0); // 0スタート

    if(!ng){
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
