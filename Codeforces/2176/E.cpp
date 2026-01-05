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
        lz.assign(4*n, -1);
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, 0);
        lz.assign(4*n, -1);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != -1){ //0 can be assigned? change!
            st[p] = (ll)(r - l + 1) * lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] = lz[p]; // += increment = update
                lz[2 * p + 1] = lz[p];
            } 
            lz[p] = -1;
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
    return a + b;
}

ll el(){
    return 0LL;
}

const int N = 200005, M = 20; // M >= log2(N)
int sparse[N][M];
vector<int> a;
void build(int n){
    for(int i=1;i<=n;i++) sparse[i][0] = a[i];
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            if((i + (1 << (j-1))) <= n) sparse[i][j] = max(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

int query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return max(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        a.resize(n+1);
        vector<int> c(n+1);
        vector<int> p(n+1);
        vector<ll> ans(n+1);
        a[0] = 0;
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<pair<int, int>> vp;
        for(int i=1;i<=n;i++){
            cin >> c[i];
            vp.push_back({c[i], i});
        }
        sort(vp.begin(), vp.end(), greater<pair<int,int>>());
        for(int i=1;i<=n;i++) cin >> p[i];
        int mx = *max_element(a.begin(), a.end());
        int mxv = INF_INT;
        for(int i=1;i<=n;i++){
            if(a[i] == mx) mxv = min(mxv, c[i]);
        }
        ans[0] -= mxv;
        for(int i=1;i<=n;i++){
            if(a[p[i]] == mx) mxv = 0;
            ans[i] -= mxv;
        }
        SegmentTreeLazy<ll, op, el> st(n+1);
        build(n);
        for(auto [val, j] : vp){
            int l = j, r = j;
            for(int jmp=n/2;jmp>=1;jmp>>=1){
                while(l - jmp >= 1 && query(l-jmp,j) == a[j]) l -= jmp;
                while(r + jmp <= n && query(j, r + jmp) == a[j]) r += jmp;
            }
            st.update(l, r, val);
        }
        ans[0] += st.query(1, n);
        for(int i=1;i<=n;i++){
            int j = p[i];
            int l = j, r = j;
            for(int jmp=n/2;jmp>=1;jmp>>=1){
                while(l - jmp >= 1 && query(l-jmp,j) == a[j]) l -= jmp;
                while(r + jmp <= n && query(j, r + jmp) == a[j]) r += jmp;
            }
            st.update(l, r, 0);
            ans[i] += st.query(1, n);
        }
        for(int i=0;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";

    }
}
