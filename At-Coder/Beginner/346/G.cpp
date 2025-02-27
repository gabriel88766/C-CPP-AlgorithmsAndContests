#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st;
    vector<int> lz;
    int n;
    SegmentTreeLazy(vector<int> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, 0);
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.resize(4*n);
        lz.assign(4*n, 0);
        vector<int> v(n, 0);
        build(v, 0, n-1, 1);
    }
    void build(vector<int> &v, int l, int r, int p){
        if(l == r){ st[p] = {v[l], 1}; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != 0){ //0 can be assigned? change!
            st[p].first += lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] += lz[p]; // += increment = update
                lz[2 * p + 1] += lz[p];
            } 
            lz[p] = 0;
        }
    }

    T query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return nullel();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, int val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, int val){
        update(i, j, val, 0, n-1, 1);
    }
};

pair<int, int> op(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return make_pair(a.first, a.second + b.second);
    else return min(a, b);
}

pair<int, int> el(){
    return make_pair(INF_INT, INF_INT);
}


const int N = 2e5+3;
vector<int> idx[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        idx[x].push_back(i);
    }
    set<tuple<int,int,int>> ins, rem;
    for(int i=1;i<=n;i++){
        for(int j=0;j<idx[i].size();j++){
            int lf = j == 0 ? 1 : idx[i][j-1] + 1;
            int rg = j + 1 == idx[i].size() ? n : idx[i][j+1] - 1;
            //from [lf, idx[j]], join seg [idx[j], rg];
            ins.insert({lf, idx[i][j], rg});
            rem.insert({idx[i][j] + 1, idx[i][j], rg});
        }
    }
    SegmentTreeLazy<pair<int,int>, op, el> st(n+1);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        while(ins.size() && get<0>(*ins.begin()) == i){
            auto [a, b, c] = *ins.begin();
            ins.erase(ins.begin());
            st.update(b, c, 1);
        }
        while(rem.size() && get<0>(*rem.begin()) == i){
            auto [a, b, c] = *rem.begin();
            rem.erase(rem.begin());
            st.update(b, c, -1);
        }
        ans += n - st.query(0, n).second + 1;
    }
    cout << ans << "\n";
}
