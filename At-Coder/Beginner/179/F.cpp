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
        st[l] = val; //assign or increment?
        while(l > 1){
            l >>= 1;
            st[l] = op(st[2*l], st[2*l+1]); //merge op
        }
    }
};

int op(int a, int b){
    return min(a, b);
}

int el(){
    return INF_INT;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, q;
    cin >> n >> q;
    ll ans = (n-2);
    ans *= (n-2);
    vector<int> aux(max(n, q)+1, INF_INT);
    vector<SegmentTree<int, op, el>> st(2, SegmentTree<int, op, el>(aux));
    vector<SegmentTree<int, op, el>> st2(2, SegmentTree<int, op, el>(aux));
    for(int i=1;i<=q;i++){
        int j, x;
        cin >> j >> x;
        j--;
        int tim = st[j].query(1, x-1);
        //find the smallest value in xx[j^1] which time insertion is lower than tim
        // cout << tim << " ";
        if(tim == INF_INT) tim = q;
        int vx = st2[j^1].query(1, tim);
        if(vx == INF_INT){
            ans -= n-2;
        }else{
            ans -= vx - 2;
        }
        // cout << ans << "\n";
        st[j].update(x, i);
        st2[j].update(i, x);
    }
    cout << ans << "\n";
}
