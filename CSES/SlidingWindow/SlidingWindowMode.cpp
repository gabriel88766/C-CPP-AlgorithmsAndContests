#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTree{
    vector<T> st;
    int n;
    SegmentTree(vector<T> &v){
        n = v.size();
        st.resize(2*n);
        build(v);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(2*n);
    }
    void build(vector<T> &v){
        for(int i=n;i<2*n;i++) st[i] = v[i-n];
        for(int i=n-1;i>=1;i--) st[i] = op(st[2*i], st[2*i+1]); //merge op
    }
    T query(int l, int r){
        T ans = nullel();
        l += n, r += n;
        while(l <= r){
            int no = l, c = 1;
            while(!(no & 1) && (r-l+1) >= (c << 1)){
                c <<= 1;
                no >>= 1;
            }
            ans = op(ans, st[no]); //merge op
            l += c;
        }
        return ans;
    }
    void update(int l, int val){
        l += n;
        st[l].first += val; //assign or increment?
        while(l > 1){
            l >>= 1;
            st[l] = op(st[2*l], st[2*l+1]); //merge op
        }
    }
};

pair<int, int> merge(pair<int, int> a, pair<int, int> b){
    if(a.first > b.first) return a;
    else if(a.first < b.first) return b;
    else if(a.second > b.second) return b;
    else return a;
}

pair<int, int> el(){
    return make_pair(-1, -1);
}

vector<int> av;
int get_pos(int val){
    return lower_bound(av.begin(), av.end(), val) - av.begin();
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        av.push_back(v[i]);
    }
    sort(av.begin(), av.end());
    av.resize(unique(av.begin(), av.end()) - av.begin());
    vector<pair<int, int>> ini(av.size());
    for(int i=1;i<av.size();i++) ini[i].second = i;
    SegmentTree<pair<int,int>, merge, el> st(ini);


    for(int i=1;i<=n;i++){
        st.update(get_pos(v[i]), 1);
        if(i >= k){
            cout << av[st.st[1].second] << " ";
            st.update(get_pos(v[i-k+1]), -1);
        }
    }
    cout << "\n";
}
