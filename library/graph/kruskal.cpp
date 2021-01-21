#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define int long long
#define fi first
#define se second
#define debug(x) cerr << #x << ": " << x << '\n' 
#define yn {puts("Yes");}else{puts("No");} // if(a == b) yn;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int INF = 1001001001;
constexpr long long LINF = 1001001001001001001;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

struct UnionFind {
    vector<int> par, siz;
    UnionFind (int n) : par(n, -1), siz(n, 1) {};

    int root(int x) {
        if(par[x] == -1){
            return x;
        }
        return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y){
        if(issame(x, y)) return false;
        x = root(x);
        y = root(y);
        if(size(x) > size(y)) {
            par[y] = x;
        }
        else{
            par[x] = y;
        }
        siz[x] += siz[y];
        siz[y] = siz[x];
        return true;
    }

    int size(int x){
        return siz[root(x)];
    }
};


void solve() {
    int n,m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>>vec(m);
    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        vec[i] = {z, {x, y}};
    }

    // クラスカル法
    // sortに O(ElogE) = O(ElogV), for文ににO(Eα(V))より，O(ElogV) 
    sort(vec.begin(), vec.end());
    UnionFind uf(n);
    int ans = 0;
    for(int i=0;i<m;i++){
        int d = vec[i].first;
        int x = vec[i].second.first;
        int y = vec[i].second.second;
        if(uf.issame(x, y)) continue;
        ans += d;
        uf.unite(x, y);
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