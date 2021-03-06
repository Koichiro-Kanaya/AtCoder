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
    UnionFind (int n) : par(n, -1), siz(n, 1) {};

    int root(int a){
        if(par[a] == -1) return a;
        return par[a] = root(par[a]);
    }

    bool issame(int a, int b) {
        return root(a) == root(b);
    }

    bool unite(int a, int b){
        int x = root(a);
        int y = root(b);
        if(x == y) return false;

        if(siz[x] < siz[y])swap(x, y);

        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x){
        return siz[root(x)];
    }
};

void solve() {
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
