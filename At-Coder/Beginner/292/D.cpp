#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];

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

vector<int> adj[N];
vector<int> comp[N];
set<int> cmp;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    init();
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        unite(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool ok = true;
    for(int i=1;i<=n;i++){
        cmp.insert(get(i));
        comp[get(i)].push_back(i);
    }
    for(auto x : cmp){
        int sz = comp[x].size();
        int edgs = 0;
        for(auto y : comp[x]){
            edgs += adj[y].size();
        }
        edgs /= 2;
        if(sz != edgs) ok = false;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
