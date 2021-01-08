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

void insert_sort(vector<int>&a){
    int n = a.size();
    for(int i=1;i<n;i++){
        int v = a[i];
        int j;
        for(j=i;j>=1;j--){
            if(a[j-1] > v){
                a[j] = a[j-1];
            }
            else{
                break;
            }
        }
        a[j] = v;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    insert_sort(a);
    for(int i=0;i<n;i++){
        cout << a[i] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
