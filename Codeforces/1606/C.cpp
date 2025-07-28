#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll po10[19];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    
    po10[0] = 1;
    for(int i=1;i<=18;i++) po10[i] = po10[i-1] * 10;
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v(n+1);
        for(int i=0;i<n;i++) cin >> v[i];
        v[n] = 18;
        ll ans = 0;
        for(int i=0;i<n;i++){
            if(po10[v[i+1] - v[i]] > k+1){
                ans += po10[v[i]] * (k+1);
                break;
            }else{
                ll cur = po10[v[i+1] - v[i]] - 1;
                ans += cur * po10[v[i]];
                k -= cur;
            }
        }
        cout << ans << "\n";
    }
}
