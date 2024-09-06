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
    void update(int l, T val){
        l += n;
        st[l] += val; //assign or increment?
        while(l > 1){
            l >>= 1;
            st[l] = op(st[2*l], st[2*l+1]); //merge op
        }
    }
};

int op(int a, int b){
    return max(a, b);
}

int el(){
    return 0;
}

int opm(int a, int b){
    return min(a, b);
}

int elm(){
    return INF_INT;
}

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

    ll query(int i, int j, int l, int r, int p){
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

ll op2(ll a, ll b){
    return a + b;
}

ll el2(){
    return 0LL;
}

struct Query{
    int l, r, j;
    bool operator< (const Query &q) const{
        return r > q.r;
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];

        vector<int> val(n+1);
        vector<ll> ans(n+1);
        for(int i=1;i<=n;i++){
            val[i] = v[i] - i + n;
        }
        SegmentTree<int, op, el> st(2*n+5);
        for(int i=1;i<=n;i++){
            st.update(val[i], 1);
            if(i > k) st.update(val[i-k], -1);
            if(i >= k) ans[i] = k-st.query(1, 2*n-1);
            else ans[i] = INF_INT;
        }
        SegmentTree<int, opm, elm> st2(ans);
        vector<pair<int,int>> rel(n+1);
        set<pair<ll, ll>> sax;
        for(ll i=k;i<=n;i++){
            int x = i;
            for(int j=n/2;j>=1;j>>=1){
                while(x-j >= k && st2.query(x-j, i-1) > ans[i]) x -= j;
            }
            int y = i;
            for(int j=n/2;j>=1;j>>=1){
                while(y+j <= n && st2.query(i, y+j) >= ans[i]) y += j;
            }
            rel[i] = {x, y};
            ans[i] *= (i-x+1);
            /*auto it = sax.lower_bound({y, 0});
            if(it != sax.end() && it->first == y){
                auto p = *sax;
                sax.erase(it);
                p->second += 
            }*/
        }
        
    
        // hs between 1 and 2*n-1
        //-4 = -3,-2,-1,0,1
        //0 = 1,2,3,4,5
        //4 = 5,6,7,8,9
        vector<Query> vq(q);
        vector<ll> ansq(q);
        for(int i=0;i<q;i++){
            cin >> vq[i].l >> vq[i].r;
            vq[i].j = i;
        }
        sort(vq.begin(), vq.end());
        int p = 0;
        /*SegmentTreeLazy<ll, op2, el2> st2(n+1);



        for(int i=n;i>=k;i--){
            // for x:[i + k - 1, n],  a[x] = min(val, a[x])
            //for queries, ans[j] = st.query(l+k-1, r);
            
            int x = i + k - 1;
            ll val = ans[x];
            for(int y=n/2;y>=1;y>>=1){
                while(x + y <= n && st2.query(x+y, x+y) >= val) x += y;
            }
            st2.update(i+k-1, x, val);
            while(p < q && vq[p].r == i){
                ansq[vq[p].j] = st2.query(vq[p].l+k-1, vq[p].r);
                p++;
            }
        }
        for(int i=0;i<q;i++) cout << ansq[i] << "\n";*/

    }
}
