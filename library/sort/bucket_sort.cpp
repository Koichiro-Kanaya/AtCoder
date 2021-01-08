#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int INF = 1001001001;
constexpr long long LINF = 1001001001001001001;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void bucket_sort(vector<int>&a){
    int n = a.size();
    
    // 各要素の数をカウントする．
    // num[v] : vの数
    int MAX = 0;
    for(int i=0;i<n;i++){
        MAX = max(MAX, a[i]);
    }
    vector<int>num(MAX+1, 0);
    for(int i=0;i<n;i++){
        num[a[i]]++;
    }

    // numの累積和を取る．
    // sum[v] : v以下の個数
    vector<int>sum(MAX+1, 0);
    for(int i=1;i<MAX+1;i++){
        sum[i] = sum[i-1] + num[i];
    }

    // a2にsortした配列を入れる
    vector<int>a2(n);
    for(int i=0;i<n;i++){
        a2[--sum[a[i]]] = a[i]; // sum[a[i]]をデクリメントしてからa2にsum[a[i]]を入れている．sum[a[i]]--だと，a2にsum[a[i]]を入れてからデクリメントすることになる．
    }

    a = a2;
}

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    bucket_sort(a);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
