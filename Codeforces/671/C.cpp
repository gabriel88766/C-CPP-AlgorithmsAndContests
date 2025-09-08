#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, typename S, T (*op)(T, T), T (*el)(), S (*id)(),\
 S (*composition)(S, S), T (*apply)(T, S, int)>
struct SegmentTreeLazy{
    vector<T> st;
    vector<S> lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, id());
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, el());
        lz.assign(4*n, id());
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != id()){ //0 can be assigned? change!
            st[p] = apply(st[p], lz[p], r-l+1);
            if(l != r){
                lz[2 * p] = composition(lz[2*p], lz[p]); // += increment = update
                lz[2 * p + 1] = composition(lz[2*p + 1], lz[p]);
            } 
            lz[p] = id();
        }
    }

    T query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return el();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, S val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, S val){
        update(i, j, val, 0, n-1, 1);
    }
    //try to find the biggest index such that st[p] <= x
    int find(int x, int l, int r, int p){
        push(l, r, p);
        if(l == r) return l;
        int m = (l + r)/2;
        push(m+1, r, 2*p+1);
        if(st[2*p+1] <= x) return find(x, m+1, r, 2*p+1);
        else return find(x, l, m, 2*p);
    }
};

ll op(ll a, ll b){
    return a + b;
}

ll el(){
    return 0LL;
}

ll id(){
    return 0LL;
}

ll composition(ll a, ll b){
    return b;
}

ll apply(ll stv, ll lzv, int len){
    return lzv * len;
}

ll idmn(){
    return -1;
}
ll opmn(ll a, ll b){
    return min(a, b);
}

ll elmn(){
    return INF_LL;
}

ll applymn(ll stv, ll lzv, int len){
    return lzv;
}

const int N = 2e5+3;
ll v[N], cnt[N];
vector<ll> oc[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        oc[v[i]].push_back(i);
    }
    ll ans = 0;
    SegmentTreeLazy<ll, ll, op, el, id, composition, apply> stsum(n+1);
    SegmentTreeLazy<ll, ll, opmn, elmn, idmn, composition, applymn> stmin(n+1);
    for(int i=1;i<=n;i++){
        stsum.update(i, i, i-1);
        stmin.update(i, i, i-1);
    }

    for(int i=200000;i>=1;i--){
        ll mn = n+1, smn = n+1, mx = 0, smx = 0;
        for(int j=i;j<=200000;j+=i){
            for(auto x : oc[j]){
                if(x < mn){
                    smn = mn;
                    mn = x;
                }else if(x < smn){
                    smn = x;
                }
                if(x > mx){
                    smx = mx;
                    mx = x;
                }else if(x > smx){
                    smx = x;
                }
            }
        }
        if(smx == 0) continue;
        if(smn < n){
            ll xx = smn + 1;
            ans += (n * (n - xx + 1) - stsum.query(xx, n)) * i;
            stsum.update(xx, n, n);
            stmin.update(xx, n, n);
        }
        if(smx > 1){
            ll xx = smx - 1;
            if(stmin.query(1, 1) <= xx){
                ll cmx = stmin.find(xx, 0, n, 1);
                cmx = min(cmx, xx);
                ans += (xx * (cmx) - stsum.query(1, cmx)) * i;
                stsum.update(1, cmx, xx);
                stmin.update(1, cmx, xx);
            }
        }
        ll xx = mx - 1;
        ll yy = mn + 1;
        if(stmin.query(yy, yy) <= xx){
            ll cmx = stmin.find(xx, 0, n, 1);
            cmx = min(cmx, xx);
            ans += (xx * (cmx - yy + 1) - stsum.query(yy, cmx)) * i;
            stsum.update(yy, cmx, xx);
            stmin.update(yy, cmx, xx);
        }
    }
    cout << ans << "\n";
}
