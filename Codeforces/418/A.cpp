#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    if(n >= 2*k + 1){
        cout << n*k << "\n";
        for(int i=1;i<=k;i++){
            vector<bool> vis(n+1, false);
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    int cur = j;
                    while(!vis[cur]){
                        vis[cur] = true;
                        int nv = cur + i;
                        if(nv > n) nv -= n;
                        cout << cur << " " << nv << "\n";
                        cur = nv;
                    }
                }
            }
        }
    }else cout << "-1\n";
}
