#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 2e5+6;
int st[4*N];
int  u[N];
int ans[N];
int opened[N], closed[N];
int n;

int query(int i, int j, int l = 1, int r = n, int node = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[node];
    return query(i, j, l, (l + r)/2, 2 * node) + query(i, j, (l + r)/2 + 1, r, 2 * node + 1); //some operation
}

void update(int pos, ll value, int l = 1, int r = n, int node = 1){
    if(pos < l || pos > r) return;
    if(l == r) {st[node] = value;  return;}
    update(pos, value, l, (l + r)/2, 2 * node);
    update(pos, value, (l + r)/2 + 1, r, 2 * node + 1);
    st[node] = st[2 * node] + st[2 * node + 1]; //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    n = 2 * t;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        u[i] = aux;
        if(!opened[aux]) opened[aux] = i;
        else{
            closed[aux] = i;
            update(i, 1);
        } 
    } 
    for(int i=1;i<=n;i++){
        if(opened[u[i]] == i){
            ans[u[i]] = closed[u[i]] - opened[u[i]] - 2 * query(i, closed[u[i]] - 1) - 1;
            update(closed[u[i]], 0);
        }
    }

    for(int i=1; i<=t;i++) cout << ans[i] << " ";
}
