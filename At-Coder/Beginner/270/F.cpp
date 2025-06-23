#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1;}
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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> air(n+1), har(n+1);
    for(int i=1;i<=n;i++){
        cin >> air[i].first;
        air[i].second = i;
    }
    for(int i=1;i<=n;i++){
        cin >> har[i].first;
        har[i].second = i;
    }
    sort(har.begin(), har.end());
    sort(air.begin(), air.end());
    ll ans = INF_LL;
    vector<tuple<int, int, int>> edg, std;
    for(int i=1;i<=m;i++){
        int a, b, z;
        cin >> a >> b >> z;
        std.push_back({z, a, b});
    }
    for(int i=0;i<4;i++){
        ll cst = 0;
        init(n);
        edg.clear();
        if(i & 1){
            cst += air[1].first;
            for(int j=2;j<=n;j++){
                edg.push_back({air[j].first, air[1].second, air[j].second});
            }
        }
        if(i & 2){
            cst += har[1].first;
            for(int j=2;j<=n;j++){
                edg.push_back({har[j].first, har[1].second, har[j].second});
            }
        }
        for(auto x : std) edg.push_back(x);
        sort(edg.begin(), edg.end());
        for(auto [w, a, b] : edg){
            if(get(a) != get(b)){
                unite(a, b);
                cst += w;
            }
        }
        if(sz[get(1)] == n) ans = min(ans, cst);
    }
    cout << ans << "\n";
}
