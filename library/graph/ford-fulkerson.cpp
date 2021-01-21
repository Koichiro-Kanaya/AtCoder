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

struct Graph1 {
    // 辺を表す構造体
    // rev : 逆辺(to, from)が，G[to]の中で何番目の要素なのか
    // cap : 辺(from, to)の容量
    struct Edge {
        int rev, from, to, cap;
        Edge(int r, int f, int t, int c) :
            rev(r), from(f), to(t), cap(c) {};
    };

    // 隣接リスト
    vector<vector<Edge>> list;

    // 頂点数N
    Graph1(int N = 0) : list(N) {};

    // グラフの頂点数取得
    size_t size(){
        return list.size();
    }

    // GraphインスタンスをGとして，
    // G.list[v]をG[v]として書けるようにしておく．
    vector<Edge> &operator [] (int i) {
        return list[i];
    }

    // 辺e = (u, v)の逆辺(v, u)を取得する．
    Edge& redge(const Edge &e){
        return list[e.to][e.rev];
    }

    // 辺e = (u, v)に流量fのフローを流す．
    // e = (u, v)の流量がfだけ減少する．
    // このとき，逆辺(v, u)の流量を増やす．
    void run_flow(Edge &e, int f){
        e.cap -= f;
        redge(e).cap += f;
    }

    // 頂点fromから頂点toへ容量capの辺を張る．
    // このとき，toからfromへも容量0の辺を張っておく．
    void addedge(int from, int to, int cap) {
        int fromrev = (int)list[from].size();
        int torev = (int)list[to].size();
        list[from].push_back(Edge(torev, from, to, cap));
        list[to].push_back(Edge(fromrev, to, from, 0));
    }
};

struct FordFulkerson {
    vector<int>seen;
    FordFulkerson() {}

    // 残余グラフ上でs-tパスを見つける(深さ優先探索)
    // 返り値はs-tパス上の容量の最小値(見つからなかったら0)
    // f : sからvへ到達した過程の各辺の容量の最小値
    int fodfs(Graph1 &G, int v, int t, int f){
        if(v == t) return f;

        // 深さ優先探索
        seen[v] = true;
        for(auto &e : G[v]){
            if(seen[e.to]) continue;

            // 容量0の辺は実際には存在しない
            if(e.cap == 0) continue;

            // s-tパスを探す
            // 見つかったらflowはパス上の最小容量
            // 見つからなかったらf = 0
            int flow = fodfs(G, e.to, t, min(f, e.cap));

            // s-tパスが見つからなかったら次辺を試す
            if(flow == 0) continue;

            // 辺eに容量flowのフローを流す
            G.run_flow(e, flow);

            // s-tパスを見つけたらパス上最小容量を返す
            return flow;
        }

        // s-tパスが見つからなかったことを示す
        return 0;
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