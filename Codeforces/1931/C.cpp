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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }
        int ans = n-1;
        if(v[1] == v[n]){
            int p1 = 1;
            while(p1 + 1 <= n && v[p1+1] == v[1]) p1++;
            int p2 = n;
            while(p2 - 1 >= 1 && v[p2-1] == v[n]) p2--;
            if(p1 == n) ans = 0;
            else{
                ans = p2-p1-1;
            }
        }else{
            int p = 1;
            while(p+1 <= n && v[p+1] == v[1]) p++;
            ans = n - p;
            p = n;
            while(p-1 >= 1 && v[p-1] == v[n]) p--;
            ans = min(ans, p-1);
        }
        cout << ans << "\n";

    }
}
