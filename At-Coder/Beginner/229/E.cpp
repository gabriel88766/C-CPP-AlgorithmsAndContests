#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N], ans[N];
int cur = 0;

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

bool unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    return true;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        adj[a].push_back(b);
    }
    for(int i=n;i>=1;i--){
        ans[i] = cur;
        cur++;
        for(auto v : adj[i]){
            if(unite(i, v)) cur--;
        }
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << "\n";
    }
}
