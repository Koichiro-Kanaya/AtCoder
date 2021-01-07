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

struct Heap {
    vector<int>heap;
    Heap(){};
    
    void push(int x){
        heap.push_back(x);
        int index = heap.size() - 1;
        while(heap[index] > heap[(index-1) / 2] && index > 0){
            swap(heap[index], heap[(index-1) / 2]);
            index = (index-1) / 2;
        }
    }

    int top(){
        if(heap.size() > 0){
            return heap[0];
        }
        return -1;
    }

    void pop(){
        if(heap.size() == 0){
            cout << "heap is now empty." << endl;
            return;
        }
        swap(heap[0], heap[heap.size()-1]);
        heap.pop_back();
        int index = 0;
        while(true){
            if(2*index+2 <= heap.size()-1 && heap[index] < max(heap[2*index+1], heap[2*index+2])){
                if(heap[2*index+1] > heap[2*index+2]){
                    swap(heap[index], heap[2*index+1]);
                    index = 2*index+1;
                }
                else{
                    swap(heap[index], heap[2*index+2]);
                    index = 2*index+2;
                }
            }
            else if (2*index+1 == heap.size()-1 && heap[index] < heap[2*index+1]){
                swap(heap[index], heap[2*index+1]);
                break;
            }
            else{
                break;
            }
        }
    }

};

void solve() {
    Heap h;
    h.push(5);
    h.push(3);
    h.push(6);
    h.push(8);
    cout << h.top() << endl;
    h.pop();
    cout << h.top() << endl;
    h.pop();
    cout << h.top() << endl;
    h.pop();
    h.pop();
    h.pop();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
