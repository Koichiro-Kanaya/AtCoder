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

bool cmp(pair<int,int>&a, pair<int,int>&b){
    return a.se < b.se;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin(), a.end(), [](pair<int,int>a, pair<int,int>b){
        return a.second < b.second;});
    bool flag = true;
    int tmp = 0;
    for(int i=0;i<n;i++){
        if(tmp+a[i].fi > a[i].se){
            flag = false;
        }
        tmp += a[i].fi;
    }
    if(flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
