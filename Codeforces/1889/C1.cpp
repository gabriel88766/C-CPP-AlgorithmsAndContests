#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+6;
pair<int, int> st[4*N];
int lz[4*N];
int n;

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ lz[p] = 0,  st[p] = {0,1}; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = {0,r-l+1}, lz[p] = 0;
}

void push(int l, int r, int p){
    if(lz[p]){ //0 can be assigned? change!
        st[p].first += lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
        if(l != r){
            lz[2 * p] += lz[p]; // += increment = update
            lz[2 * p + 1] += lz[p];
        } 
        lz[p] = 0;
    }
}

void update(int i, int j, int val, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
    update(i, j, val, l, (l + r)/2, 2 * p);
    update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
    if(st[2*p].first == st[2 * p + 1].first){
        st[p] = {st[2*p].first, st[2*p].second + st[2*p+1].second};
    }else st[p] = min(st[2*p], st[2*p+1]);
}

int sparse[N][M];

void builds(int n){
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = max(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

ll query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return max(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int m, k;
        cin >> n >> m >> k;
        build();
        set<int> s;
        vector<vector<int>> v(n+1);
        for(int i=1;i<=n;i++){
            s.insert(i);
        }
        vector<pair<int,int>> vp(m);
        for(int i=0;i<m;i++){
            int l, r;
            cin >> l >> r;
            vp[i] = {l, r};
            update(l, r, 1);
            vector<int> rml;
            for(auto it = s.lower_bound(l); it != s.end() && *it <= r; ++it){
                v[*it].push_back(i);
                if(v[*it].size() > k) rml.push_back(*it);
            }
            while(rml.size()){
                s.erase(rml.back());
                rml.pop_back();
            }
        }
        //choose 2 unite, 2 disjoint
        int ans = 0;
        vector<pair<int,int>> h;
        vector<int> cnt(m, 0);
        vector<int> dj;
        for(auto x : s){
            if(v[x].size() == 1){
               cnt[v[x][0]]++;
               dj.push_back(v[x][0]);
            }else if(v[x].size() == 2){
                auto p1 = vp[v[x][0]];
                auto p2 = vp[v[x][1]];
                update(p1.first, p1.second, -1);
                update(p2.first, p2.second, -1);
                if(st[1].first == 0) ans = max(ans, st[1].second);
                update(p1.first, p1.second, 1);
                update(p2.first, p2.second, 1);
            }
        }
        dj.resize(unique(dj.begin(), dj.end()) - dj.begin());
        int p = 0;
        int old = 0;
        if(st[1].first == 0) old = st[1].second;

        for(int i=0;i<m;i++){
            sparse[i][0] = cnt[i];
        }
        for(int i = 0; i < dj.size();i++){
            while(p < dj.size()){
                if(vp[i].second >= vp[dj[p]].first) p++;
                else break;
            }
            int x = 0;
            for(int i=p;i<dj.size();i++) x = max(cnt[p], x);
            ans = max(ans, old + cnt[i] + x);
        }
        cout << ans << "\n";


    }
}
