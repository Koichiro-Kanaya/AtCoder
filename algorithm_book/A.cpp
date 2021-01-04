#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n' 

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int INF = 1001001001;
constexpr long long LINF = 1001001001001001001;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    int n;
    cin >> n;
    vector<int>a(n), b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    int tmp = -1;
    int ans = 0;
    vector<bool>vec(n,false);
    for(int i=0;i<n;i++){
        auto itr = lower_bound(a.begin(), a.end(), b[i]);
        if(tmp < itr - a.begin()){
            tmp = itr - a.begin();
            ans++;
        }
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
