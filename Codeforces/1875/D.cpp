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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int mex = 0;
        sort(v.begin(), v.end());
        for(int i=0;i<n;i++){
            if(v[i] <= mex){
                if(v[i] == mex) mex++;
            }else break;
        }
        vector<ll> dp(mex+1, INF_LL);
        vector<ll> qt(mex, 0);
        dp[mex] = 0;
        for(int i=0;i<n;i++){
            if(v[i] < mex){
                qt[v[i]]++;
            }else break;
        }

        for(ll i=mex-1;i>=0;i--){
            for(ll j=mex;j>i;j--){
                dp[i] = min(dp[i], dp[j] + (qt[i]-1)*j + i);
            }
        }
        
        cout << dp[0] << "\n";

    }
}
