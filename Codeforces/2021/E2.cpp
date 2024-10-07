#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;   
int p[N], sz[N];
ll dp[N][N], aux[N];
vector<int> vc[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b, ll w){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(vc[a].size() < vc[b].size()) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    dp[a][0] = vc[a].size() * w;
    dp[b][0] = vc[b].size() * w;
    for(int i=0;i<=sz[a]+sz[b]; i++) aux[i] = INF_LL;
    for(int i=0;i<=sz[a];i++){
        for(int j=0;j<=sz[b];j++){
            if(i == 0 && j == 0){
                if(vc[a].size() || vc[b].size()) aux[i] = INF_LL;
                else aux[i] = 0;
            }else aux[i+j] = min(aux[i+j], dp[a][i] + dp[b][j]);
        }
    }
    for(int i=0;i<=sz[a]+sz[b];i++) dp[a][i] = aux[i];
    
    for(auto x : vc[b]) vc[a].push_back(x);
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
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = INF_LL;
            }
            dp[i][1] = 0;
        }
        for(int i=0;i<p;i++){
            int x;
            cin >> x;
            vc[x].push_back(x);
        }
        for(int i=0;i<m;i++){
            int a, b, w;
            cin >> a >> b >> w;
            vec[i] = {a, b, w};
        }
        sort(vec.begin(), vec.end());
        for(auto [a, b, w] : vec){
            if(get(a) != get(b)){
                unite(a, b, w);
            }
        }
        int rt = get(1);
        for(int i=1;i<=n;i++) cout << dp[rt][i] << " ";
        cout << "\n";


        for(int i=1;i<=n;i++) vc[i].clear();
        
    }
}
