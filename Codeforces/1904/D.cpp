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

int op1(int a, int b){
    return max(a, b);
}

int el1(){
    return 0;
}

int op2(int a, int b){
    return min(a, b);
}

int el2(){
    return INF_INT;
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
        vector<int> a(n), b(n);
        vector<vector<int>> oc(n+1);
        for(int i=0;i<n;i++){
             cin >> a[i];
             oc[a[i]].push_back(i);
        }
        for(int i=0;i<n;i++) cin >> b[i];
        SegmentTree<int, op1, el1> st1(a);
        SegmentTree<int, op2, el2> st2(b);
        bool ok = true;
        for(int i=0;i<n;i++){
            if(a[i] == b[i]) continue;
            if(a[i] > b[i]){
                ok = false;
                break;
            }else{
                //find first eq b[i] in left and right
                auto it = lower_bound(oc[b[i]].begin(), oc[b[i]].end(), i);
                if(it != oc[b[i]].begin()){
                    int ind = *prev(it);
                    if(st1.query(ind, i) <= b[i] && st2.query(ind, i) >= b[i]) continue;
                }
                if(it != oc[b[i]].end()){
                    int ind = *it;
                    if(st1.query(i, ind) <= b[i] && st2.query(i, ind) >= b[i]) continue;
                }
                ok = false;
                break;
            }
            
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
