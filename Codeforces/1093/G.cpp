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
    SegmentTree(){}
    SegmentTree(vector<T> &v){
        n = v.size();
        st.resize(2*n);
        build(v);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(2*n, -INF_INT);
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
    return max(a, b);
}

int el(){
    return -INF_INT;
}
const int M = 32;
SegmentTree<int, op, el> st[M];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    int xx = 1 << k;
    vector<vector<int>> v(n+1, vector<int>(k));
    for(int i=0;i<xx;i++) st[i] = SegmentTree<int, op, el>(n+1);

    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            cin >> v[i][j];
        }
        for(int j=0;j<xx;j++){
            int cur = 0;
            for(int b=0;b<k;b++){
                if(j & (1 << b)) cur += v[i][b];
                else cur -= v[i][b];
            }
            st[j].update(i, cur);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int tq;
        cin >> tq;
        if(tq == 1){
            int i;
            cin >> i;
            for(int j=0;j<k;j++){
                cin >> v[i][j];
            }
            for(int j=0;j<xx;j++){
                int cur = 0;
                for(int b=0;b<k;b++){
                    if(j & (1 << b)) cur += v[i][b];
                    else cur -= v[i][b];
                }
                st[j].update(i, cur);
            }
            
        }else{
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for(int m=0;m<xx/2;m++){
                int om = m ^ (xx-1);
                ans = max(ans, st[m].query(l, r) + st[om].query(l, r));
            }
            cout << ans << "\n";
        }
    }

}