#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)(),\
 void (*pushfn)(int, int, int, std::vector<T>&, std::vector<T>&)>
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
        pushfn(l, r, p, st, lz);
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

void push_sum(int l, int r, int p, vector<ll> &st, vector<ll> &lz){
    if(lz[p] != 0){ //0 can be assigned? change!
        st[p] += (ll)(r - l + 1) * lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
        if(l != r){
            lz[2 * p] += lz[p]; // += increment = update
            lz[2 * p + 1] += lz[p];
        } 
        lz[p] = 0;
    }
}

//declare as SegmentTreeLazy<ll, op, el, push_sum> st(n+1);

ll opmin(ll a, ll b){
    return min(a, b);
}

ll elmin(){
    return INF_INT;
}

void push_min(int l, int r, int p, vector<ll> &st, vector<ll> &lz){
    if(lz[p] != 0){ //0 can be assigned? change!
        st[p] += lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
        if(l != r){
            lz[2 * p] += lz[p]; // += increment = update
            lz[2 * p + 1] += lz[p];
        } 
        lz[p] = 0;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];

        SegmentTreeLazy<ll, op, el, push_sum> st(n+1);
        SegmentTreeLazy<ll, opmin, elmin, push_min> st2(n+1);
        ll ans = 0;
        int nv = 1;
        for(int i=1;i<=n;i++){
            ans += v[i];
            st.update(1, v[i], 1);
            st2.update(1, v[i], 1);
            int k = 1;
            for(int j=n;j>=1;j>>=1){
                while(k + j <= n && st2.query(1, k+j) > 0) k += j;
            }
            if(k >= nv){
                st.update(1, nv, -1);
                st2.update(1, nv, -1);
                ans -= nv++;
            }else{
                st.update(1, k, -1);
                st2.update(1, k, -1);
                ans -= k;
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
 