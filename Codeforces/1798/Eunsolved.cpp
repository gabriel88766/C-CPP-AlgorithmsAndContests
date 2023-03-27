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
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        vector<ll> testn(n);
        vector<ll> maxv(n, 0);
        for(int i=n-1;i>= 0;i--){
            if(v[i] == (n-i-1)){
                testn[i] = 1;
            }else if(i+v[i]+1 < n && testn[i+v[i]+1]){
                testn[i] = testn[i+v[i]+1] + 1;
            }else testn[i] = 0;
        }

        vector<ll> ans(n-1);

        for(int i=n-2;i>=0;i--){
            maxv[i] = maxv[i+1];
            maxv[i] = max(maxv[i], testn[i+1]);
            if(v[i] == testn[i+1]) ans[i] = 0;
            else if(testn[i+1] || v[i] <= maxv[i]+1) ans[i] = 1;
            else if(i+v[i]+1 < n && v[i] <= maxv[i+v[i]+1]+2) ans[i] = 1;
            else ans[i] = 2;
        
        }
        for(int i=0;i<n-1;i++) cout << ans[i] << " "; 
        cout << "\n";
    }
}
