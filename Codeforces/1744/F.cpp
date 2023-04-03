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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> pos(n);
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            pos[aux] = i;
        }
        ll ans = 0;
        int l = n-1, r = 0;
        for(int i=0;i<n;i++){
            l = min(l, pos[i]);
            r = max(r, pos[i]);
            int lmin = r-l+1;
            int lmax = min(n, 2*(i+1));
            int forb = i < (n-1) ? pos[i+1] : -1;

            if(forb >= l && forb <= r) continue;
            
            if(forb < l){
                for(int j=forb+1;j<=l;j++){
                    int maxv = j+lmax-1;
                    ans += max(min(maxv, n-1)-r+1, 0);
                }
            }else{
                for(int j=r;j<=forb-1;j++){
                    int minv = j-lmax+1;
                    ans += max(l-max(minv, 0)+1, 0);
                }
            }
        }
        cout << ans << "\n";
        

    }
}
