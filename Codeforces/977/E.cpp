#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N], dg[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    map<int,int> mpc;
    vector<vector<int>> comp;
    init();
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        dg[a]++, dg[b]++;
        unite(a, b);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int k = get(i);
        if(mpc[k]) comp[mpc[k]-1].push_back(i);
        else{
            mpc[k] = ++cnt;
            vector<int> aux;
            aux.push_back(i);
            comp.push_back(aux);
        }
    }
    for(int i=0;i<comp.size();i++){
        bool ok = true;
        for(auto u : comp[i]){
            if(dg[u] != 2) ok = false;
        }
        if(ok) ans++;
    }
    cout << ans;
}
