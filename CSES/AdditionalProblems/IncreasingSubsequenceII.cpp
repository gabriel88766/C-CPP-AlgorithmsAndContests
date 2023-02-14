#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+6;
ll st[4*N];
ll v[N];
int n;

ll query(int i, int j, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return (query(i, j, l, (l + r)/2, 2 * p) + query(i, j, (l + r)/2 + 1, r, 2 * p + 1)) % MOD; //some operation
}

void update(int pos, ll value, int l = 1, int r = n, int p = 1){
    if(pos < l || pos > r) return;
    if(l == r) {st[p] = value; return;}
    update(pos, value, l, (l + r)/2, 2 * p);
    update(pos, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = (st[2 * p] + st[2 * p + 1]) % MOD; //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    vector<pair<int,int>> vp;
    cin >> n;
    vp.push_back({0,0});
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        vp.push_back({a, i});
    }
    sort(vp.begin(), vp.end());
    stack<pair<int,int>> updst;
    int cur = 0;
    for(int i=1;i<=n;i++){
        if(vp[i].first != cur){
            while(!updst.empty()){
                auto cup = updst.top();
                update(cup.first, cup.second);
                updst.pop();
            }
            cur = vp[i].first;
        }
        v[i] = 1;
        v[i] += query(1, vp[i].second);
        v[i] %= MOD;
        updst.push({vp[i].second, v[i]});
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) ans = (ans + v[i]) % MOD;
    cout << ans;
}
