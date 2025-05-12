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
        int n, k;
        cin >> n >> k;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        int l = n - k;
        int ans = 0;
        if(l % 2){
            l++;
        }
        int rl = l/2;
        int rr = n - l + 1 + l/2;
        ans = v[rr] - v[rl] + 1;
        
        cout << ans << "\n";
    }
}
