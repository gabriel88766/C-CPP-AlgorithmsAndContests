#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool adj[20][20];
bool isok[1 << 20];
ll fat[21];
ll nCr(ll n, ll k){
    return fat[n] / (fat[k] * fat[n-k]);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    fat[0] = 1;
    for(int i=1;i<=20;i++) fat[i] = fat[i-1] * i;
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        --a, --b;
        adj[a][b] = adj[b][a] = true;
    }
    for(int i=0;i<(1 << n);i++){
        if(__builtin_popcount(i) == 2){
            isok[i] = true;
            for(int u=0;u<n;u++){
                if(!(i & (1 << u))) continue;
                for(int v=0;v<n;v++){
                    if(!(i & (1 << v))) continue;
                    if(adj[u][v]) isok[i] = false;
                }
            }
        }else{
            isok[i] = true;
            for(int u=0;u<n;u++){
                if(!(i & (1 << u))){
                    if(!isok[i ^ (1 << u)]){
                        isok[i] = false;
                    }
                }
            }
        }
    }
    //subset conv
    int xv = (n+2)/3;
    ll ans = 0;
    for(int i=0;i<(1 << n);i++){
        if(__builtin_popcount(i) >= xv){
            int cm = ((1 << n) - 1) ^ i;
            for (int s=cm; s; s=(s-1)&cm){
                if(__builtin_popcount(s) > __builtin_popcount(i)) continue;
                ans++;
                //do something
            }
        }
    }
    cout << ans << "\n";
}
