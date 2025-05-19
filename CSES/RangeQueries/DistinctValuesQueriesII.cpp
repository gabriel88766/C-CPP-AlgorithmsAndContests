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

const int N = 4e5+3; //N+Q
vector<int> cd;
set<int> mp[N];
inline int get_pos(int val){
    return lower_bound(cd.begin(), cd.end(), val) - cd.begin();
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        cd.push_back(v[i]);
    }
    
    vector<tuple<int, int, int>> qr;
    for(int i=1;i<=q;i++){
        int t, a, b;
        cin >> t >> a >> b;
        cd.push_back(b);
        qr.push_back({t, a, b});
    }
    sort(cd.begin(), cd.end());
    cd.resize(unique(cd.begin(), cd.end()) - cd.begin());

    for(int i=1;i<=n;i++){
        mp[get_pos(v[i])].insert(i);
    }
    SegmentTree<int, op, el> st(n+1);
    for(int i=1;i<=n;i++){
        int pos = get_pos(v[i]);
        auto it = mp[pos].upper_bound(i);
        if(it == mp[pos].end()) st.update(i, INF_INT);
        else st.update(i, *it);
    }
    for(auto &[t, a, b] : qr){
        int pa = get_pos(v[a]);
        int pb = get_pos(b);
        if(t == 1){
            auto it1 = mp[pa].lower_bound(a);
            if(it1 != mp[pa].begin()){
                if(next(it1) != mp[pa].end()) st.update(*prev(it1), *next(it1));
                else st.update(*prev(it1), INF_INT);
            }
            mp[pa].erase(a);
            v[a] = b;
            mp[pb].insert(a);
            auto it2 = mp[pb].lower_bound(a);
            if(next(it2) == mp[pb].end()) st.update(a, INF_INT);
            else st.update(a, *next(it2)); 
            if(it2 != mp[pb].begin()){
                st.update(*prev(it2), a);
            }
            
        }else{
            int mn = st.query(a, b);
            if(mn <= b) cout << "NO\n";
            else cout << "YES\n";
        }   
    }
}
