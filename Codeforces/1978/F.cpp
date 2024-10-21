#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e6+5;
int lp[N]; // 0 if prime, 1 if not primes
void sieve(){
    for(ll i=2; i<N; i++){
        if(!lp[i]){
            for(ll j = i; j < N; j += i){
                if(!lp[j]) lp[j] = i; 
            }
        }
    }
}

vector<int> ind[N];
bool vis[N];
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
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        init(2*n+1);
        ll ans = 0;
        vector<int> rem;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            if(x == 1) ans += n;
            else{
                if(i == 1) ans += 1;
                else ans += 2;
            }
            int op = -1;
            while(x != 1){
                if(op != lp[x]){
                    op = lp[x];
                    if(!vis[op]){
                        vis[op] = true;
                        rem.push_back(op);
                    }
                    ind[op].push_back(i);
                }
                x /= lp[x];
            }
        }
        for(auto x : rem){
            for(int j=0;j<ind[x].size();j++){
                int cp = ind[x][j];
                if(cp == 1) continue;
                int np = ind[x][(j+1) % ind[x].size()];
                if(j+1 == ind[x].size()) np += n;
                if(np - cp <= k){
                    if(get(cp) != get(np)){
                        ans--;
                        unite(cp, np);
                    }
                }
            }
            for(int j=1;j<ind[x].size();j++){
                int cp = ind[x][j-1] + n;
                int np = ind[x][j] + n;
                if(np - cp <= k){
                    if(get(cp) != get(np)){
                        ans--;
                        unite(cp, np);
                    }
                }
            }
        }
        
        cout << ans << "\n";


        for(auto x : rem){
            ind[x].clear();
            vis[x] = false;
        }
    }
}
