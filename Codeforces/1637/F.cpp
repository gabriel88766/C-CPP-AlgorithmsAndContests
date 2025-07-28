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
    return max(a, b);
}

ll el(){
    return 0;
}

const int N = 2e5+3;
ll h[N];
vector<int> adj[N];
pair<ll, ll> dp[N];
ll ans = 0;
void dfs(int u, int p){
    bool ch = true;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            ch = false;
            dp[u].first += dp[v].first;
            dp[u].second = max(dp[u].second, dp[v].second);
        }
    }
    if(ch){
        dp[u] = {h[u], h[u]};
    }else{
        if(h[u] > dp[u].second){
            ll dif = h[u] - dp[u].second;
            dp[u].first += dif;
            dp[u].second += dif;
        }
    }
}

pair<ll, ll> pdp;

void dfs2(int u, int p){
    if(adj[u].size() == 1){
        ll curs = 0;
        ll curm = 0;
        for(auto v : adj[u]){
            if(v != p){
                curm = max(curm, dp[v].second);
                curs += dp[v].first;
            }
        }
        curm = max(curm, pdp.second);
        curs += pdp.first;
        if(curm < h[u]){
            ll dif = h[u] - curm;
            curm += dif;
            curs += dif;
        }
        ans = min(ans, curs + curm);
    }
    //somewhat difficult
    vector<ll> vx;
    ll sum = 0;
    for(auto v : adj[u]){
        if(v != p){
            sum += dp[v].first;
            vx.push_back(dp[v].second);
        }
    }
    SegmentTree<ll, op, el> st(vx);
    int px = -1;
    for(auto v : adj[u]){
        if(v != p){
            auto ov = pdp;
            px++;
            ll mx = 0;
            if(px > 0) mx = max(mx, st.query(0, px-1));
            if(px + 1 < vx.size()) mx = max(mx, st.query(px+1, vx.size() - 1)); 
            pdp.second = mx = max(mx, pdp.second);
            
            ll dif = 0;
            if(h[u] > mx) dif = h[u] - mx;
            pdp.first += sum - dp[v].first + dif;
            pdp.second += dif;
            dfs2(v, u);
            pdp = ov;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    if(n == 2){
        int x, ans = 0;
        cin >> x;
        ans = max(ans, 2*x);
        cin >> x;
        ans = max(ans, 2*x);
        cin >> x >> x;
        cout << ans << "\n";
        return 0;
    }
    for(int i=1;i<=n;i++) cin >> h[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int rt = -1;
    for(int i=1;i<=n;i++){
        if(adj[i].size() != 1){
            rt = i;
            break;
        }
    }
    dfs(rt, 0);
    ans = INF_LL;
    dfs2(rt, 0);
    cout << ans << "\n";
}


// 1 let dp[i] a pair, with sum of children and greatest children. Upd it if current node greater
// 2 try to do all roots dp
// 3 ans = max(ans, dp[i].first + dp[i].second) for all roots that are also leaves