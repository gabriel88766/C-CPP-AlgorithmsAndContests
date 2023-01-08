//Binary search on seg tree
#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 2e5+6;
int st[4*N];
int v[N];   
int n;

void build(int l = 1, int r = n, int node = 1){
    if(l == r){ st[node] = v[l]; return; }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
    st[node] = max(st[2 * node], st[2 * node + 1]); //some operation
}

pair<int, int> query(int value, int l = 1, int r = n, int node = 1){
    if(l == r) return {l, st[node]}; //identity element
    if(value <= st[2 * node]) return query(value, l, (l+r)/2, 2 * node);
    else return query(value, (l + r)/2 + 1, r, 2 * node + 1); //some operation
}

void update(int pos, int value, int l = 1, int r = n, int node = 1){
    if(pos < l || pos > r) return;
    if(l == r) {st[node] = value; return;}
    update(pos, value, l, (l + r)/2, 2 * node);
    update(pos, value, (l + r)/2 + 1, r, 2 * node + 1);
    st[node] = max(st[2 * node], st[2 * node + 1]); //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int m;
    cin >> n >> m;
    vector<int> u(m);
    vector<int> ans(m);
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    for(int i=0;i<m;i++) cin >> u[i];
    for(int i=0;i<m;i++){
        if(st[1] < u[i]){
            ans[i] = 0;
            continue;
        }
        
        auto r = query(u[i]);
        ans[i] = r.first;
        update(r.first, r.second - u[i]);
        
    }
    for(int i=0;i<m;i++) cout << ans[i] << " ";
}
