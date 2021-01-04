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

vector<ll>vec;

ll tribo(int n){
    if(n <= 2){
        if(vec[n] != -1){
            return vec[n];
        }
        return vec[n] = max(0, n-1);
    }
    if(vec[n] != -1){
        return vec[n];
    }
    return vec[n] = tribo(n-1) + tribo(n-2) + tribo(n-3);
}

void solve() {
    int n;
    cin >> n;
    vec.assign(n+1,-1);
    ll ans = tribo(n);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}