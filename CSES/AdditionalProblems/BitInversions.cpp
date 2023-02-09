#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+6;
ll st[4*N], pr0[4*N], pr1[4*N], su0[4*N], su1[4*N], mid1[4*N], mid0[4*N];
string s;
int n;

void build(int l = 1, int r = n, int node = 1){
    if(l == r){ 
        if(s[l-1] == '1') pr1[node] = su1[node] = mid1[node] = 1;
        else pr0[node] = su0[node] = mid0[node] = 1;
        st[node] = 1;
        return; 
    }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
    pr0[node] = pr0[2*node] == ((l+r)/2 - l + 1) ? pr0[2*node] + pr0[2*node+1] : pr0[2*node];
    pr1[node] = pr1[2*node] == ((l+r)/2 - l + 1) ? pr1[2*node] + pr1[2*node+1] : pr1[2*node];
    su0[node] = su0[2*node+1] == (r - (l+r)/2) ? su0[2*node] + su0[2*node+1] : su0[2*node+1];
    su1[node] = su1[2*node+1] == (r - (l+r)/2) ? su1[2*node] + su1[2*node+1] : su1[2*node+1];
    mid0[node] = max(mid0[2*node], max(mid0[2*node+1], su0[2*node] + pr0[2*node+1])); 
    mid1[node] = max(mid1[2*node], max(mid1[2*node+1], su1[2*node] + pr1[2*node+1]));
    st[node] = max(mid0[node], mid1[node]);
}

void update(int pos, int l = 1, int r = n, int node = 1){
    if(pos < l || pos > r) return;
    if(l == r) {
        int value;
        if(mid1[node] == 1) value = 0;
        else value = 1;
        if(value == 1){
            pr1[node] = su1[node] = mid1[node] = 1;
            pr0[node] = su0[node] = mid0[node] = 0;
        } else{
            pr0[node] = su0[node] = mid0[node] = 1;
            pr1[node] = su1[node] = mid1[node] = 0;
        } 
        st[node] = 1;
        return;
    }
    update(pos, l, (l + r)/2, 2 * node);
    update(pos, (l + r)/2 + 1, r, 2 * node + 1);
    pr0[node] = pr0[2*node] == ((l+r)/2 - l + 1) ? pr0[2*node] + pr0[2*node+1] : pr0[2*node];
    pr1[node] = pr1[2*node] == ((l+r)/2 - l + 1) ? pr1[2*node] + pr1[2*node+1] : pr1[2*node];
    su0[node] = su0[2*node+1] == (r - (l+r)/2) ? su0[2*node] + su0[2*node+1] : su0[2*node+1];
    su1[node] = su1[2*node+1] == (r - (l+r)/2) ? su1[2*node] + su1[2*node+1] : su1[2*node+1];
    mid0[node] = max(mid0[2*node], max(mid0[2*node+1], su0[2*node] + pr0[2*node+1])); 
    mid1[node] = max(mid1[2*node], max(mid1[2*node+1], su1[2*node] + pr1[2*node+1]));
    st[node] = max(mid0[node], mid1[node]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    cin >> s;
    n = s.size();
    build();
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        update(a);
        cout << st[1] << "\n";
    }
}
