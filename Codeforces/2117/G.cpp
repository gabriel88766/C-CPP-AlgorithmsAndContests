#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N], mn[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1; mn[i] = INF_INT;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b, int w){
    a = get(a);
    b = get(b);
    if(a == b){
        mn[a] = min(mn[a], w);
        return;
    }
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    mn[a] = min({mn[a], mn[b], w});
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        vector<tuple<int, int, int>> edg;
        int n, m;
        cin >> n >> m;
        for(int i=1;i<=m;i++){
            int a, b, w;
            cin >> a >> b >> w;
            edg.push_back({w, a, b});
        }
        sort(edg.begin(), edg.end());
        init(n);
        int ans = 2e9+3;
        for(auto &[w, a, b] : edg){
            unite(a, b, w);
            if(get(1) == get(n)){
                ans = min(ans, w + mn[get(1)]);
            }
        }
        cout << ans << "\n";
    }
}
