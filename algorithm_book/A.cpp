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

void solve() {
    string s;
    cin >> s;
    stack<int>st;
    vector<pair<int,int>>vec;
    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            if(st.size() == 0){
                cout << "ERROR" << endl;
                return;
            }
            else{
                vec.push_back({st.top(), i});
                st.pop();
            }
        }
    }
    for(int i=0;i<s.size();i++){
        cout << vec.fi << " " << vec.se << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
