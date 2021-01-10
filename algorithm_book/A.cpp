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

struct UnionFind {
    vector<int>par, siz;
    UnionFind(int n) : par(n, -1), siz(n, 1) {};

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    int root(int x){
        if(par[x] == -1){
            return x;
        }
        return par[x] = root(par[x]);
    }

    bool unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y){
            return false;
        }
        if(size(x) < size(y)){
            swap(x, y);
        }
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x){
        return siz[root(x)];
    }

};

void solve() {
    int n,m;
    cin >> n >> m;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        que.push({z, {min(x, y), max(x, y)}});
    }
    UnionFind uf(n);
    int cost = 0;
    while(!que.empty()){
        int w = que.top().fi;
        int x = que.top().se.fi;
        int y = que.top().se.se;
        que.pop();
        if(uf.issame(x, y)){
            continue;
        }
        uf.unite(x, y);
        cost += w;
    }
    cout << cost << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
