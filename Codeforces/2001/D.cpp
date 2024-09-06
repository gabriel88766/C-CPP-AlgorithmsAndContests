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
        st.resize(4*n);
        build(v, 0, n-1, 1);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(4*n);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){st[p] = v[l]; return;}
        build(v, l, (l+r)/2, 2*p);
        build(v, (l+r)/2+1, r, 2*p+1);
        st[p] = op(st[2*p], st[2*p+1]);
    }
    T query(int i, int j, int l, int r, int p){
        if(j < l || i > r) return nullel(); 
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, T value, int l, int r, int p){
        if(i < l || i > r) return;
        if(l == r) {st[p] = value; return;}
        update(i, value, l, (l + r)/2, 2 * p);
        update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); //some operation
    }
    void update(int i, T value){
        update(i, value, 0, n-1, 1);
    }
    int findmn(int l, int r, int p, int ord){ //
        if(l == r) return l;
        int m = (l + r)/2;
        if(st[2*p] <= ord) return findmn(l, m, 2*p, ord);
        else return findmn(m+1, r, 2*p+1, ord);
    }
    int findmn(int ord){
        return findmn(0, n-1, 1, ord);
    }
    int findmx(int l, int r, int p, int ord){ //
        if(l == r) return l;
        int m = (l + r)/2;
        if(st[2*p+1] <= ord) return findmx(m+1, r, 2*p+1, ord);
        else return findmx(l, m, 2*p, ord);
    }
    int findmx(int ord){
        return findmx(0, n-1, 1, ord);
    }
};

int opm(int a, int b){
    return min(a, b);
}

int elm(){
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
        vector<int> v(n+1);
        int cnt = 0;
        set<pair<int,int>> aux;
        vector<int> mx(n+1, INF_INT), mn(n+1, INF_INT);
        vector<vector<int>> nums(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            mx[v[i]] = i;
            nums[v[i]].push_back(i);
            if(mn[v[i]] == INF_INT){
                mn[v[i]] = i;
                aux.insert({i, v[i]});
            }
        }
        for(int i=1;i<=n;i++) if(nums[i].size()) cnt++;
        SegmentTree<int, opm, elm> st(mx);
        SegmentTree<int, opm, elm> st2(mn);
        vector<int> ans;
        for(int i=0;i<cnt;i++){
            int ind;
            if(i % 2){
                ind = st2.findmn(st.query(0, n));
            }else{
                ind = st2.findmx(st.query(0, n));
            }
            int val = st2.query(ind, ind);
            ans.push_back(ind);
            st.update(ind, INF_INT);
            st2.update(ind, INF_INT);
            while(aux.size() && aux.begin()->first <= val){
                auto p = *aux.begin();
                aux.erase(aux.begin());
                if(p.first == val) continue;
                auto it = lower_bound(nums[p.second].begin(), nums[p.second].end(), val);
                assert(it != nums[p.second].end());
                p.first = *it;
                aux.insert(p);
                st2.update(p.second, p.first);
            }
        }
        cout << ans.size() << "\n";
        for(auto x : ans ) cout << x << " ";
        cout << "\n";
    }
}
