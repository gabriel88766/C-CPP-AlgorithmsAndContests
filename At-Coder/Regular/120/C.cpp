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

ll op(ll a, ll b){
    return a + b;
}

ll el(){
    return 0LL;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", st din); //test input
    int n;
    cin >> n;
    map<int, vector<int>> mp1, mp2;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        x += i;
        mp1[x].push_back(i);
    }
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        x += i;
        mp2[x].push_back(i);
    }
    bool ok = true;
    for(auto [a, b] : mp1){
        if(mp2.count(a) && mp2[a].size() == b.size()){
            //then it's alright!
        }else{
            ok = false;
        }
    }
    if(ok){
        map<int, int> cls;
        int cnt = 0;
        for(auto [a, b] : mp2){
            cls[a] = ++cnt;
        }
        vector<int> ax(n+1), bx(n+1);
        vector<vector<int>> oc(cnt+1);
        for(auto [a, b] : mp1){
            for(auto x : b) ax[x] = cls[a];
        }
        for(auto [a, b] : mp2){
            for(auto x : b) bx[x] = cls[a];
        }
        for(int i=n;i>=1;i--){
            oc[ax[i]].push_back(i);
        }
        //now solve this new old problem.
        ll ans = 0;
        vector<ll> aux(n+1, 1);
        aux[0] = 0;
        SegmentTree<ll, op, el> st(aux);
        for(int i=1;i<=n;i++){
            int cur = bx[i];
            int foc = oc[cur].back();
            oc[cur].pop_back();
            ans += st.query(1, foc) - 1;
            st.update(foc, 0);
        } 
        cout << ans << "\n";
    }else cout << "-1\n";
}
