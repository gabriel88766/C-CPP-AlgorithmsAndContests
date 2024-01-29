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
    int n;
    cin >> n;
    vector<vector<int>> ind(11);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        ind[v[i]].push_back(i);
    }
    vector<int> fin(n+1, INF_INT);
    SegmentTree<int, op, el> st(fin);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=min(v[i] - 1, 10 - v[i]);j++){
            int cur = j;
            for(int k=0;k<=1;k++){
                int x1 = v[i] - cur;
                int x2 = v[i] + cur;
                cur *= -1;
                auto it1 = lower_bound(ind[x1].begin(), ind[x1].end(), i);
                auto it2 = lower_bound(ind[x2].begin(), ind[x2].end(), i+1);
                if(it1 == ind[x1].begin()) continue;
                else it1 = prev(it1);
                if(it2 == ind[x2].end()) continue;
                //cout << i << " " << *it1 << " "  << *it2 << "\n";
                if(fin[*it1] > *it2){
                    fin[*it1] = *it2;
                    st.update(*it1, *it2);
                }
                
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        int x = st.query(i, n);
        //cout << i << " " << x << "\n";
        if(x != INF_INT){
            ans += n - x + 1;
        }
    }
    cout << ans << "\n";
}
