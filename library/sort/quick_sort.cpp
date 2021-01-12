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

// in-placeだけど不安定
void quick_sort(vector<int>&a, int left, int right){
    if(right - left <= 1) return;

    int pivot_index = (left + right) / 2; // 適当にここでは中点とする．
    int pivot = a[pivot_index];
    swap(a[pivot_index], a[right - 1]); // pivotと右側をswap．

    int i = left; // iは左詰めされたpivotの未満要素の右側を表す．
    for(int j=left; j<right-1; j++){
        if(a[i] < pivot){ // pivot未満のものがあったら左に詰めていく．
            swap(a[i], a[j]);
            i++; // swap(a[i++], a[j]);とも書ける．
        }
    }
    swap(a[i], a[right - 1]); // pivotを適切な場所に挿入．

    // 再帰的に解く．
    quick_sort(a, left, i); // 左半分(pivot未満)
    quick_sort(a, i+1, right); // 右半分(pivot以上)
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
