#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

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
        st[l] = val; //assign or increment?
        while(l > 1){
            l >>= 1;
            st[l] = op(st[2*l], st[2*l+1]); //merge op
        }
    }
};

ll op(ll a, ll b){
    return a + b;
}

ll el(){
    return 0LL;
}


struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
        if(u < 0) return (Mint(1)/v).pow(-u);
        Mint ans = 1;
        Mint aux = *this;
        while(u){
            if(u & 1) ans *= aux;
            aux *= aux;
            u >>= 1;
        }
        return ans;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint& operator*= (const Mint &u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint& operator+= (const Mint &u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint& operator-= (const Mint &u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint& operator/= (const Mint &u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint &u) const { return v == u.v;}
    bool operator!= (const Mint &u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    cin >> m;
    vector<ll> vx(m);
    for(int i=0;i<m;i++) cin >> vx[i];
    auto ord = vx;
    ord.push_back(0);
    sort(ord.begin(), ord.end());
    SegmentTree<ll, op, el> st1(m+1), st2(m+1);
    ordered_set<ll> sx;
    ordered_set<int> sind;
    int pb;
    auto getLeft = [&](int idx){
        return st1.query(0, idx) * ord[idx] - st2.query(0, idx);
    };
    auto getRight = [&](int idx){
        return -st1.query(idx, m) * ord[idx] + st2.query(idx, m);
    };
    auto getval = [&](int ko){
        return max(getLeft(*sind.find_by_order(ko)), getRight(*sind.find_by_order(ko+2)));
    };
    ll avg = 0;
    for(int i=0;i<m;i++){
        int idx = lower_bound(ord.begin(), ord.end(), vx[i]) - ord.begin();
        avg += vx[i];
        sind.insert(idx);
        sx.insert(vx[i]);
        st1.update(idx, 1);
        st2.update(idx, vx[i]);
        if(i >= 2){
            if(i == 2){
                pb = *sind.begin();
            }else{
                ll cavg = avg / (i+1);
                int pm = sx.order_of_key(cavg);
                int ls = max(pm - 2, 0);
                int rs = min(pm + 2, i - 2);
                ll minv = INF_LL;
                // cout << i << " " << ls << " " << rs << "\n";
                for(int j=ls;j<=rs;j++){
                    ll cval = getval(j);
                    if(cval < minv){
                        minv = cval;
                        pb = j;
                    }
                }
                



                pb = *sind.find_by_order(pb);

            }
        }else continue;
        int i1 = pb;
        int i2 = *next(next(sind.find(pb)));
        Mint ans = max(getLeft(i1), getRight(i2));
        ans /= i-1;
        cout << ans << "\n";
    }
    // cout << "\n";
}
