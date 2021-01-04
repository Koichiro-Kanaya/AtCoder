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

bool P(int x){

}

// P(x) == true となる最小の値xを返す．
ll binary_search(){
    ll left, right; // P(left) = false, P(right) = trueとなるようにする．
    while(right - left > 1){
        ll mid = left + (right - left) / 2;
        if(P(mid)) right = mid;
        else left = mid;
    }
    return right;
}

void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
