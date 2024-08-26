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

int opm(int a, int b){
    return max(a, b);
}

int elm(){
    return 0;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    v[0] = -INF_INT;
    sort(v.begin() + 1, v.end());
    SegmentTree<int, opm, elm> dp(n+1);
    dp.update(0, 1);
    for(int i=1;i<=n;i++){
        int x = i;
        for(int k=i/2;k>=1;k>>=1){
            while(x - k >= 0 && (v[i] - v[x-k]) <= d) x -= k;
        }
        x--;
        int y = i - k;
        if(y >= x && dp.query(x, y)) dp.update(i, 1);
    }
    if(dp.query(n, n)) cout << "YES\n";
    else cout << "NO\n";
}
