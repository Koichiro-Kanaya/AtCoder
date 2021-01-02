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


vector<int> merge_sort(vector<int>&a){
    int n = a.size();
    if(n <= 1){
        return a;
    }

    vector<int>left,right;
    for(int i=0;i<n/2;i++){
        left.push_back(a[i]);
    }
    left = merge_sort(left);
    for(int i=n/2;i<n;i++){
        right.push_back(a[i]);
    }
    right = merge_sort(right);

    int left_id = 0, right_id = 0;
    vector<int>vec;
    while(true){
        if(left_id == left.size() && right_id == right.size()){
            break;
        }
        else if(left_id == left.size()){
            vec.push_back(right[right_id]);
            right_id++;
        }
        else if(right_id == right.size()){
            vec.push_back(left[left_id]);
            left_id++;
        }
        else{
            if(left[left_id] < right[right_id]){
                vec.push_back(left[left_id]);
                left_id++;
            }
            else{
                vec.push_back(right[right_id]);
                right_id++;
            }
        }
    }
    return vec;
}
