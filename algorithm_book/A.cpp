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
    int n,w,k;
    cin >> n >> w >> k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    // dp[i][j] i個目の整数までで，重さjにできる最小の個数
    vector<vector<int>>dp(n+1, vector<int>(w+1, INF));
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=w;j++){
            if(dp[i][j] < INF){
                chmin(dp[i+1][j], dp[i][j]);
            }
            if(j-a[i]>=0 && dp[i][j-a[i]] < INF){
                chmin(dp[i+1][j], dp[i][j-a[i]] + 1);
            }
        }
    }
    if(dp[n][w] <= k){
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
