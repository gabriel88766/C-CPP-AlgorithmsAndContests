#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;



const int N = 300005, M = 20; // M >= log2(N)
int sparse[N][M];
int sparse2[N][M];
vector<int> v;
int n;

void build(){
    for(int i=1;i<=n;i++) sparse[i][0] = sparse2[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            if((i + (1 << (j-1))) <= n) sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]), sparse2[i][j] = max(sparse2[i][j-1], sparse2[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1], sparse2[i][j] = sparse2[i][j-1];
        }
    }
}

ll query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

ll query2(int a, int b){
    if(a == b) return sparse2[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return max(sparse2[a][pot], sparse2[b - (1 << pot) + 1][pot]);
}

int st[4*N];

void clear(int l = 1, int r = n, int p = 1){
    if(l == r){ st[p] = 0; return; }
    clear(l, (l+r)/2, 2 * p);
    clear((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}

ll querysg(int i, int j, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return querysg(i, j, l, (l + r)/2, 2 * p) + querysg(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, int value, int l = 1, int r = n, int p = 1){
    if(i < l || i > r) return;
    if(l == r) {st[p] += value; return;}
    update(i, value, l, (l + r)/2, 2 * p);
    update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        v.resize(n+1);
        set<pair<int,int>> s;
        for(int i=1;i<=n;i++){
             cin >> v[i];
             s.insert({v[i], i});
        }
        ll ans = 0;
        for(ll i=0;i<n-1;i++){
            ans += ((n-1-i) * (n-i))/2;
        }
        //sub ->
        build();
        clear();
        vector<int> cur;
        set<pair<int,pair<int,int>>> evt1, evt2;
        for(int i = 1; i <= n-1; i++){
            int l = i+1, r = i+1;
            for(int j = n/2; j>=1; j >>= 1){
                while(r + j < n && query(l, r+j) > v[i]) r += j;
            }
            if(cur.size() && cur.back() > v[i]) cur.clear();
            cur.push_back(v[i]);
            if(v[r] > v[i]) r++;
            ans -= (r-l) * (ll)(cur.size());
            evt1.insert({l, {cur.size(), i}});
            evt2.insert({r, {-cur.size(), i}});
        }
        cur.clear();
        for(int i = n; i >= 1; i--){
            while(evt2.size() && prev(evt2.end())->first == i){
                update(prev(evt2.end())->second.second, prev(evt2.end())->second.first);
                evt2.erase(prev(evt2.end()));
            }
            while(evt1.size() && prev(evt1.end())->first == i){
                update(prev(evt1.end())->second.second, prev(evt1.end())->second.first);
                evt1.erase(prev(evt1.end()));
            }
            int l = i-1, r = i-1;
            for(int j = n/2; j>=1; j >>= 1){
                while(l - j >= 0 && query2(l - j, r) < v[i]) l -= j;
            }
            if(cur.size() && cur.back() < v[i]) cur.clear();
            cur.push_back(v[i]);
            if(v[l] < v[i]) l--;
            ans -= (r-l+querysg(l, r)) * (ll)(cur.size());
        }
        cout << ans << "\n";
    }
}           
