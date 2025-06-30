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


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edg(m+1);
    for(int i=1;i<=m;i++){
        cin >> edg[i].first >> edg[i].second;
    }
    int k;
    cin >> k;
    vector<int> ae(k);
    for(int i=0;i<k;i++) cin >> ae[i];
    int p = 0;
    for(int i=1;i<=m;i++){
        if(p < k && ae[p] == i) p++;
        else unite(edg[i].first, edg[i].second);
    }
    set<int> cp;
    for(int i=1;i<=n;i++) cp.insert(get(i));
    vector<int> adjc(n+1);
    for(auto x : ae){
        if(get(edg[x].first) == get(edg[x].second)) continue;
        adjc[get(edg[x].first)]++;
        adjc[get(edg[x].second)]++;
    }
    int ce = 0, co = 0;
    for(auto x : cp){
        if(adjc[x] % 2) co++;
        else ce++;
    }
    if(co == 0 || co == 2) cout << "Yes\n";
    else cout << "No\n";
}
