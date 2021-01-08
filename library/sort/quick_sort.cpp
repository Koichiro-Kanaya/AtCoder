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

void quick_sort(vector<int>&a, int left, int right){
    if(right - left == 1){
        return;
    }
    int mid = left + (right - left) / 2;
    int pivot = a[mid];
    swap(a[mid], a[right - 1]);
    int i = left, j = left;
    while(j < right){
        if(a[j] < pivot){
            swap(a[i], a[j]);
            i++, j++;
        }
        else{
            j++;
        }
    }
    swap(a[i], a[right - 1]);
    quick_sort(a, left, mid);
    quick_sort(a, mid, right);
}

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    quick_sort(a, 0, n);
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
