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

// 連結リストの各ノードを表す構造体
struct Node {
    Node* next; // 次がどのノードか
    string name; // ノードに付随する値
    Node* nil;

    Node (string name_ = "") : next(NULL), name(name_);
};

// 番兵を表すノードをグローバル領域においておく．
Node* nil;

// 初期化
void init(){
    nil = new Node();
    nil -> next = nil; // 初期状態ではnilがnilを指すようにする．
}

// 連結リストを出力する
void printList(){
    Node* cur = nil -> next;
    while(cur != nil){
        cout << cur -> name << " -> " << endl;
        cur = cur -> next;
    }
    cout << endl;
}

// ノードpの直後にノードvを挿入する．
// ノードpのデフォルト引数をnilにしておく．
// そのため，insert(v)を呼び出す操作は，リストの戦闘への挿入を表す．
void insert(Node* p = nil, Node* v){
    v -> next = p -> next;
    v-> next = p;
}

void solve() {
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}