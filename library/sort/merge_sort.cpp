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


void merge_sort(vector<int>&a, int left, int right){
    // [left, right)
    if (right - left == 1){
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(a, left, mid); // 左半分をsort
    merge_sort(a, mid, right); // 右半分をsort

    vector<int>buf;
    for(int i=left;i<mid;i++){
        buf.push_back(a[i]);
    }
    for(int i=right-1;i>=mid;i--){
        buf.push_back(a[i]);
    }

    int r = buf.size()-1;
    int l = 0;
    int index = left;
    while(r>=l){
        if(buf[l] <= buf[r]){
            a[index] = buf[l];
            l++;
        }
        else{
            a[index] = buf[r];
            r--;
        }
        index++;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    merge_sort(a, 0, n);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
