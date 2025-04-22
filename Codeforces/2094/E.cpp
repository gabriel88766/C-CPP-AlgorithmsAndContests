#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int v[N];
ll qt[30];
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
        for(int j=0;j<30;j++) qt[j] = 0;
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=1;i<=n;i++){
            for(int j=0;j<30;j++){
                if(v[i] & (1 << j)) qt[j]++;
            }
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ll cur = 0;
            for(int j=0;j<30;j++){
                if(v[i] & (1 << j)){
                    cur += (1LL << j) * (n - qt[j]);
                }else{
                    cur += (1LL << j) * qt[j];
                }
            }
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
}
