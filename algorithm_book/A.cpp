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

ll K;
int ans = 0;
map<ll, vector<bool>>mp;

void func(ll n) {
    if(10*n + 3 <= K){
        mp[10*n + 3] = {true, mp[n][1], mp[n][2]};
        if(mp[10*n + 3][0] && mp[10*n + 3][1] && mp[10*n + 3][2]){
            ans++;
        }
        func(10*n+3);
    }
    if(10*n + 5 <= K){
        mp[10*n + 5] = {mp[n][0], true, mp[n][2]};
        if(mp[10*n + 5][0] && mp[10*n + 5][1] && mp[10*n + 5][2]){
            ans++;
        }
        func(10*n+5);
    }
    if(10*n + 7 <= K){
        mp[10*n + 7] = {mp[n][0], mp[n][1], true};
        if(mp[10*n + 7][0] && mp[10*n + 7][1] && mp[10*n + 7][2]){
            ans++;
        }
        func(10*n+7);
    }
    else{
        return;
    }
}

void solve() {
    cin >> K;
    mp[3] = {true, false, false};
    func(3);
    mp[5] = {false, true, false};
    func(5);
    mp[7] = {false, false, true};
    func(7);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
