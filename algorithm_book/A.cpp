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


void solve() {
    int n, w;
    cin >> n >> w;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<vector<bool>>dp(n+1, vector<bool>(w+1, false));
    for(int i=0;i<n+1;i++){
        dp[i][0] = true;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<w+1;j++){
            if(j-a[i] >= 0 && dp[i][j-a[i]]){
                dp[i+1][j] = true;
            }
            if(dp[i][j]){
                dp[i+1][j] = true;
            }
        }
    }
    if(dp[n][w]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
