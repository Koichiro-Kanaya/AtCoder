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


int stl()
{
    // S.substr(l)
    // 文字列 S の l 文字目から最後の文字までの部分文字列を返す関数です。

    // S.substr(l, r)
    // 文字列 S の l 文字目から l+r-1 文字目までの部分文字列を返す関数です。

    // min({a1, a2, ..., an})
    // {a1, a2, ..., an} の中で最小のものを返します。
    // maxも一緒

    // *min_element(c + l, c + r)
    // {c[l], c[l+1], ..., c[r-1]} の中で最小のものを返します。

    // swap(a, b)
    // 変数 a と b の値を入れ替えることができます。

    // __gcd(a, b)
    // 2 つの整数 a, b の最大公約数を返すことができます。
    // 最小公倍数を返す標準ライブラリの関数はありませんが、a と b の最小公倍数は a / __gcd(a, b) * b で計算することができます。
    // a * b / __gcd(a, b) よりもオーバーフローを起こしづらい。

    // rand()
    // 0 以上 2^31−1 以下のランダムな整数を返す関数です。
    // main関数の冒頭に srand((unsigned)time(NULL)); をつけると、実行ごとに乱数生成結果が変わります。

    // clock()
    // プログラム実行開始から何単位時間経過したかを整数で返す関数です。
    // CLOCKS_PER_SECは、定数です。環境によって1 秒が何単位時間か異なるので、秒数を知りたいときに使えます。
    // つまり、実行開始からの秒数は clock()/CLOCKS_PER_SEC で表されます。

    // reverse()
    // reverse(a.begin() + l, a.end() + r)で、a[l], a[l+1], ..., a[r-1] を逆順に並び替えます。
    // 文字列 str を逆順にしたい場合は、reverse(str.begin(), str.end()) のように書いてください。

    // sort()
    // sort(a.begin(), a.end())で、a[l], a[l+1], ..., a[r-1] を小さい順に並び替えます。
    // sort(a.begin(), a.end(), greater<int>())　で、a[0], a[1], ..., a[N-1] を大きい順に並び替えます。
    // sort(a.begin(), a.end(), cmp); (aはpairのvector)で，
    // bool cmp(pair<int,int>&a, pair<int,int>&b){
        // return a.second < b.second;
    // }
    // ってやると，pairのsecondの小さい順に並んでくれる．
    // また，ラムダ式を用いて，
    // sort(a.begin(), a.end(), [](pair<int,int>&a, pair<int,int>&b) return {a.second < b.second;});
    // とやるのもスマート．


    // vector
    // vectorは、動的な配列を表す型です。
    // a.push_back(x) は、O(1)で、a の末尾に x を追加します。
    // a.pop_back() は、O(1)で、aの末尾の要素を取り除きます。

    // stack
    // stack<int> a; は、stack 型の変数 a を定義します。
    // a.push(x)　は、スタック a の一番上に要素 x を積みます。
    // a.pop() は、スタック a の一番上の要素を取り除きます。
    // a.top() は、スタック a の一番上の要素を返す関数です。例えば、下から順に {3, 1, 4} と積み上げられている場合、a.top() の値は 4 です。
    // a.size() は、スタック a の要素数を整数で返す関数です。
    // a.empty() は、スタック a の要素数が 0 である場合 true、1 以上である場合 false を返す関数です。
    // push、pop、top などの計算量はすべて O(1) です。実質的には vector の下位互換ですが、アルゴリズムなどの参考書で stack が利用されることが多い。

    // queue
    // queue< int > a; は、queue 型の変数 a を定義します。
    // a.push(x) は、キュー a の最後尾に要素 x を入れます。
    // a.pop() は、キュー a の一番前の要素を取り除きます。
    // a.front() は、キュー a の一番前の要素を返す関数です。例えば、前から順に a = {3, 1, 4} である場合、3 を返します。
    // a.size() キュー a の要素数を返す関数です。
    // a.empty() キュー a の要素数が 0 である場合 true、1 以上である場合 false を返す関数です。
    // push、pop、front などの計算量はすべて O(1) です。

    // priority_queue
    // a を priority_queue 型の変数、x を適当な型の変数または値とします。
    // a.push(x) 優先度付きキュー a に要素 x を追加します。
    // a.pop() a の中の最も小さい要素（設定によっては、最も大きい要素）を取り除きます。
    // a.top() a の中の最も小さい要素（設定によっては、最も大きい要素）の値を返す関数です。
    // a.size() a の要素数を返す関数です。
    // a.empty() a の要素数が 0 の場合 true、1 以上である場合 false を返す関数です。
    // N を優先度付きキューに入っている要素数とするとき、push、pop、top の計算量は O(logN) です。
    // ---------------------------------------------------------------------------------------------
    // 変数の定義方法がやや特殊なので、書いておきます。以下のように、最も小さい値を取り出したい場合は greater、最も大きい値を取り出したい場合は less を使います。
    //      int 型の要素を持ち、最も小さい値を取り出す形の priority_queue を定義する場合
    //      priority_queue<int, vector<int>, greater<int>> que;
    //      int 型の要素を持ち、最も大きい値を取り出す形の priority_queue を定義する場合
    //      priority_queue<int, vector<int>, less<int>> que;

    // map
    // a.clear() マップ a を初期化します。
    // a.count(x) これが0か1かで、mapにxという値が入っているかいないかの判定に使用することができます。
    // mapには、同じキーの値を1つしか保存できません。
    // N を今まで map 型変数にアクセスした数とするとき、マップのある特定の番地へのアクセスにかかる計算量は O(logN)程度です。
    // また、mapの要素を抽出したい際は、
    // for(auto m : mp){
    //     m.fi;
    //     m.se;
    // }
    // for (auto itr = mp.begin(); itr != mp.end(); itr++){
    //     itr->first; // で何かの操作を行う。
    // }
    // みたいな

    // lower_bound() (めぐる式(条件の時): https://qiita.com/drken/items/97e37dd6143e33a64c8c#2-%E4%B8%80%E8%88%AC%E5%8C%96%E3%81%97%E3%81%9F%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2%E6%B3%95)
    // 二分探索 をすることができる関数です。
    // vector a があったとして、auto b = lower_bound(a.begin(), a.end(), x) とすると、
    // b は、*bで、vector a の中で、x以上の最小の値を返します。
    // b-a.begin() で、x以上の最小の値のindexを返します。
    // 例1
    // vector<int>a={1,2,3,4,6,6,7};
    // auto b = lower_bound(a.begin(), a.end(), 5);
    // cout<<*b<<endl; -> 6
    // cout<<b-a.begin()<<endl; -> 4
    // 例2
    // vector<int>a={1,2,3,4,5,5,6,6};
    // auto b = lower_bound(a.begin(),a.end(), 5);
    // cout<<*b<<endl; -> 5
    // cout<<b-a.begin()<<endl; -> 4

    // set (要素が常にソートされた状態の配列のようなもの。multiset とは違い、重複するデータを保持することはできない。)
    // 集合を管理することができるデータ構造です。集合に要素を追加したり、削除したり、二分探索したりできます。
    // a.insert(x) 集合 a に要素 x を追加する。但し、既に x が集合 a にある場合は追加しない。（multiset の場合、既に要素が 1 個以上あっても追加する。）
    // a.erase(x) 集合 a から要素 x を削除する。（multiset の場合、要素 x をすべて削除する。）
    // a.erase(y) 集合 a からイテレーター y の要素を削除する。（この場合、multiset の場合でも 1 個だけ消すことができる。）
    // a.lower_bound(x) 集合 a の中で x 以上である最小の要素を指すイテレーターを返す。
    // a.clear() 集合aを空にする。
    // N個の要素を持つsetに対する操作の計算量は、大体の操作でO(logN)です。

    // pair
    // 2つのpairの大小比較
    // 1つ目の要素が小さい方を小さいとみなす。1つ目の要素が同じである場合、2つ目の要素が小さい方を小さいとみなす。
    // 大きい順にするには、 sort(a.begin(), a.end(), greater<pair<int, string>>()) のようにする。
    // using PAIR = pair<string, int>;
    // sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
    //         return l.first<r.first || (l.first==r.first && l.second > r.second);
    //         });

    // tuple
    // 3つ以上の要素からなる「組」を持つことができる型です。pairは2つですが、tupleは何個でも要素を持てます。
    // 以下の3つを覚えておく。
    // ・型 v1, 型 v2, ..., 型 vn を持つ tuple 型変数を定義したい場合、tuple< v1,v2,...,vn > a; という感じのコードを書くと良いです。
    //      例えば、int 型, int 型, string 型から成る tuple 型変数を定義したい場合、tuple< int,int,string > a; などと書きます。
    // ・tuple 型変数 a の i 個目の要素にアクセスしたい場合、get< i >(a) と書けば良いです。0 個目の要素から始まることに注意してください。
    // ・make_tuple(a1,a2,...,an) で引数のコピーから tuple を生成することができます。例えば、Tuple.push_back(make_tuple(p1, p2, p3)) のようなことができる。
    // 2つのtupleの大小比較
    // 0個目の要素が小さい方を小さいとみなす。0個目の要素が等しい場合、1個目の要素が小さい方を小さいとみなす。以下同様。

    // count
    // 配列や vector のある区間の要素の中で、x がいくつ含まれるかを返す関数です。
    // vector の場合、count(v.begin(), v.end(), x) のように書けばよいです。

    // find
    // 配列や vector のある区間の要素の中に x が含まれるか、含まれる場合はどこにあるかを返す関数です。
    // a が vector の場合にも使えます。find(a.begin(), a.end(), x) とすると、関数は以下のイテレーターを返します。
    // a[0], a[1], ..., a[a.size() - 1] の中に x が含まれない場合　a.end()。
    // そうでない場合、初めて a[i] = x となるような a[i] のイテレーター。

    // next_permutation
    // 辞書順で大きくなるようにvectorが変化していく。最後は昇順に並ぶことに注意する。
    // 2,3,1
    // 3,1,2
    // 3,2,1 が出力される。
    // vector<int>a={2,3,1};
    // int n=3;
    // do {
    //     for (int i = 0; i < n; i++) {
    //         if (i) cout << ",";
    //         cout << a[i];
    //     }
    //     cout << endl;
    // } while(next_permutation(a.begin(), a.end()));

    // __builtin_popcount(x)
    // 整数xを二進数で表した時、1であるようなビットの個数を返す関数。
    // 例えば、x=42なら二進数で101010なので、3を返す。
    // また、__builtin_popcountll(x)という関数もあって、それはlong long型に対応している。

    // bitset
    // ビット集合を表す型（クラス）です。N 桁の 2 進数だと思うこともできます。ビット演算を高速に行いたいときなどに使えます。
    // 定義の仕方。
    // 例 1: 長さ 250000 の bitset（250000 桁の 2 進数だと思ってよい）を定義する。
    // bitset<250000> bs1;
    // 例 2: 長さ 8 の bitset を定義する。整数から初期化を行う。
    // bitset<8> bs2(131); // 7 ビット目から 0 ビット目への順番で、10000011 となる。
    // 例 3: 長さ 8 の bitset を定義する。2 進数から初期化を行う。
    // bitset<8> bs3("10000011"); // 7 ビット目から 0 ビット目への順番で、10000011 となる。
    // 例 4: 例 3 とやってることは変わらない。ただ bitset の長さが増えただけ。
    // bitset<2000> bs4("10000011"); // 1999 ビット目から 0 ビット目の順番で、0...010000011 となる。
    // bitsetの処理
    // a = (a^b)など (これは、bitごとのXOR。bitごとのANDは(a&b)。bitごとのORは(a|b))
    // int 型などと同じように、ビット演算（and, or, xor）をすることができます。
    // a.set(x)
    // a の x 桁目（2^x の位）を 1 に変更します。
    // a.reset(x)
    // a の x 桁目（2^x の位）を 0 に変更します。
    // a[i]
    // 配列と同様、a の i 桁目（2^i の位）にアクセスすることができます。a[i] は必ず 0 か 1 です。
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    stl();

    return 0;
}
