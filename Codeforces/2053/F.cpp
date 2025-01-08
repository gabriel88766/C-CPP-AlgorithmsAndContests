#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st, lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, 0);
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, 0);
        lz.assign(4*n, 0);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != 0){ //0 can be assigned? change!
            st[p] += lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] += lz[p]; // += increment = update
                lz[2 * p + 1] += lz[p];
            } 
            lz[p] = 0;
        }
    }

    ll query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return nullel();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        cout << i << " " << j << endl;
        if(i > j) return 0;
        
        else return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, T val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, T val){
        update(i, j, val, 0, n-1, 1);
    }
};

ll op(ll a, ll b){
    return max(a, b);
}

ll el(){
    return 0LL; 
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> gr(n, vector<int>(m));
        vector<map<int, ll>> mp(n);
        vector<ll> c1(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> gr[i][j];
                if(gr[i][j] == -1) c1[j]++;
                else mp[i][gr[i][j]] += 1;
            }
        }
        SegmentTreeLazy<ll, op, el> st(k+1);
        for(int i=1;i<n;i++){
            cout << i << endl;
            vector<int> nchk;
            ll std = 0;
            for(auto [x, y] : mp[i]){
                nchk.push_back(x);
                if(mp[i-1].count(x)) std += mp[i-1][x] * y;
            }
            for(auto [x, y] : mp[i-1]){
                nchk.push_back(x);
            }
            if(i+1 < n){
                for(auto[x, y] : mp[i+1]){
                    nchk.push_back(x);
                }
            }
            sort(nchk.begin(), nchk.end());
            nchk.resize(unique(nchk.begin(), nchk.end()) - nchk.begin());
            st.update(1, k, std);

            for(auto [x, y] : mp[i]){
                st.update(x, x, c1[i-1] * y);
            }
            cout << "here" << endl;
            //if the number was not chose, the best is either choose it or don't choose anyway
            ll bst = st.query(1, k);
            for(auto x : nchk){
                ll br = mp[i-1].count(x) ? mp[i-1][x] : 0;
                ll cr = c1[i];
                ll mv = op(st.query(1, x-1), st.query(x+1, n));
                ll bv = max(mv + br*cr, st.query(x,x) + (br + c1[i-1]) * cr);
                st.update(x, x, bv - st.query(x,x));
            }
            cout << "there" << endl;
        }
        cout << st.query(1, k) << "\n";
    }
}
