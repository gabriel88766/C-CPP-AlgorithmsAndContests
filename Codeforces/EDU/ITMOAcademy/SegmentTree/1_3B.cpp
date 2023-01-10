#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 1e5+6;
int st[4*N];
int v[N];
int n;

void build(int l = 1, int r = n, int node = 1){
    if(l == r){ st[node] = 1; return; }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
    st[node] = st[2 * node] + st[2 * node + 1]; //some operation
}

int query(int kr, int l = 1, int r = n, int node = 1){ //node
    if(l == r) return l;
    if(kr >= st[2*node + 1]) return query(kr - st[2 * node + 1], l, (l+r)/2, 2*node);
    else return query(kr, (l+r)/2 + 1, r, 2 * node + 1);
}

void update(int pos, int l = 1, int r = n, int node = 1){
    if(pos < l || pos > r) return;
    if(l == r) {st[node] = 0;  return;}
    update(pos, l, (l + r)/2, 2 * node);
    update(pos, (l + r)/2 + 1, r, 2 * node + 1);
    st[node] = st[2 * node] + st[2 * node + 1]; //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    cin >> n;
    build(); //all 1, process reverse order
    vector<int> aux(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin >> aux[i];
    }
    reverse(aux.begin(), aux.end());
    for(int i=0;i<n;i++){
        int pos = query(aux[i]);
        update(pos);
        ans.push_back(pos);
    }
    reverse(ans.begin(), ans.end());
    for(int i=0;i<n;i++) cout << ans[i] << " ";
}
