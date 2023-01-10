#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 2e5+6;
pair<ll, ll> st[4*N]; // min and #
ll v[N];
int n;

void build(int l = 1, int r = n, int node = 1){
    if(l == r){ st[node] = {v[l], 1}; return; }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
    if(st[2 * node].first != st[2 * node + 1].first) st[node] = min(st[2 * node], st[2 * node + 1]); //some operation
    else st[node] = {st[2 * node].first, st[2 * node].second + st[2 * node + 1].second};
}

pair<ll, ll> query(int i, int j, int l = 1, int r = n, int node = 1){
    if(j < l || i > r) return {INF_LL, INF_LL}; //identity element
    if(j >= r && i <= l) return st[node];
    auto lvalue = query(i, j, l, (l + r)/2, 2 * node);
    auto rvalue = query(i, j, (l + r)/2 + 1, r, 2 * node + 1);
    if(lvalue.first != rvalue.first) return min(lvalue, rvalue); //some operation
    else return {lvalue.first, lvalue.second + rvalue.second};
}

void update(int pos, ll value, int l = 1, int r = n, int node = 1){
    if(pos < l || pos > r) return;
    if(l == r) {st[node] = {value, 1};  return;}
    update(pos, value, l, (l + r)/2, 2 * node);
    update(pos, value, (l + r)/2 + 1, r, 2 * node + 1);
    if(st[2 * node].first != st[2 * node + 1].first) st[node] = min(st[2 * node], st[2 * node + 1]); //some operation
    else st[node] = {st[2 * node].first, st[2 * node].second + st[2 * node + 1].second};
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    while(q--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a==1){
            update(b+1, c);
        }else{
            auto value = query(b+1, c);
            cout << value.first <<  " " << value.second << "\n";
        }
    }
}
