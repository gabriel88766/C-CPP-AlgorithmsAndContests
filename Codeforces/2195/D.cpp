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
        vector<ll> fx(n+1);
        for(int i=1;i<=n;i++) cin >> fx[i];
        vector<ll> ans(n+1);
        for(int i=2;i<n;i++){
            ans[i] = (fx[i-1] - 2 * fx[i] + fx[i+1])/2;
        }
        //(n-1) * a[n] + (n-2) * a[n-1] + ... = fx[1];
        //(n-1) * a[1] + (n-2) * a[2] + ... = fx[n];
        ll s1 = 0, sn = 0;
        for(int i=1;i<=n;i++){
            if(i != 1 &&  i != n){
                s1 += (i - 1) * ans[i];
                sn += (n - i) * ans[i];
            }
        }
        ans[1] = (fx[n] - sn) / (n-1);
        ans[n] = (fx[1] - s1) / (n-1); 
        for(int i=1;i<=n;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
