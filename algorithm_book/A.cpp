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
    int n;
    cin >> n;
    vector<int>a(n);
    int SUM = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        SUM += a[i];
    }
    vector<bool>dp(SUM+1, false);
    dp[0] = true;
    for(int i=0;i<n;i++){
        for(int j=dp.size()-1;j>=0;j--){
            if(j-a[i] >= 0 && dp[j-a[i]]){
                dp[j] = true;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<dp.size();i++){
        if(dp[i])ans++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
