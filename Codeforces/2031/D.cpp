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

int opmin(int a, int b){
    return min(a, b);
}

int elmin(){
    return INF_INT;
}

int opmax(int a, int b){
    return max(a, b);
}

int elmax(){
    return 0;
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
        vector<pair<int,int>> vx;
        map<int, set<int>> mp;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            vx.push_back({v[i], i});
            mp[v[i]].insert(i);
        }
        SegmentTree<int, opmin, elmin> stmin(v);
        SegmentTree<int, opmax, elmax> stmax(v);
        sort(vx.begin(), vx.end(), greater<pair<int,int>>());
        vector<bool> vis(n+1, false);
        vector<int> ans(n+1);
        for(auto [val, j] : vx){
            if(!vis[j]){
                queue<int> q;
                q.push(j);
                vis[j] = true;
                stmin.update(j, INF_INT);
                stmax.update(j, 0);
                mp[v[j]].erase(j);
                while(!q.empty()){
                    auto u = q.front();
                    ans[u] = val;
                    q.pop();
                    int qmx = stmax.query(1, u);
                    while(qmx > v[u]){
                        auto idx = *mp[qmx].begin();
                        mp[qmx].erase(idx);
                        vis[idx] = true;
                        q.push(idx);
                        stmin.update(idx, INF_INT);
                        stmax.update(idx, 0);
                        qmx = stmax.query(1, u);
                    }
                    int qmn = stmin.query(u, n);
                    while(qmn < v[u]){
                        auto idx = *prev(mp[qmn].end());
                        mp[qmn].erase(idx);
                        vis[idx] = true;
                        q.push(idx);
                        stmin.update(idx, INF_INT);
                        stmax.update(idx, 0);
                        qmn = stmin.query(u, n);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
