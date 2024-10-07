#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 200005;   
int p[N], sz[N];
ll dp[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 0; dp[i] = 0;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

ll unite(int a, int b, ll w){
    a = get(a);
    b = get(b);
    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    ll v1 = dp[b] + w*sz[a];
    ll v2 = dp[a] + w*sz[b];
    ll bst = min(v1, v2);
    ll dif = bst - dp[a] - dp[b];
    dp[a] = bst;
    sz[a] += sz[b];
    return dif;
}

struct Edge{
    int a, b, w;
    bool operator< (Edge v){
        if(w != v.w) return w < v.w;
        else return make_pair(a,b) < make_pair(v.a,v.b);
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, p;
        cin >> n >> m >> p;
        vector<Edge> vec(m);
        init(n);
        for(int i=0;i<p;i++){
            int x;
            cin >> x;
            sz[x] = 1;
        }
        for(int i=0;i<m;i++){
            int a, b, w;
            cin >> a >> b >> w;
            vec[i] = {a, b, w};
        }
        sort(vec.begin(), vec.end());
        ll ans1 = 0;
        vector<ll> v;
        for(auto [a, b, w] : vec){
            if(get(a) != get(b)){
                auto aux = unite(a, b, w);
                v.push_back(aux);
                ans1 += aux;
            }
        }
        sort(v.begin(), v.end());
        for(int i=1;i<=n;i++){
            cout << ans1 << " ";
            if(v.size()){
                ans1 -= v.back();
                v.pop_back();
            }
        }
        cout << "\n";
    }
}
