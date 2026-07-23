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
        vector<ll> a(n+1);
        vector<ll> b(n+1);
        ll s1 = 0, s2 = 0;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        for(int i=1;i<=n;i++) s1 += a[i], s2 += b[i];
        if(s1 != s2) cout << "-1\n";
        else{
            int p1 = 0, p2 = 0, ans = 0;
            ll s1 = 0, s2 = 0;
            for(int i=1;;i++){
                p1++;
                s1 += a[p1];
                while(s1 != s2){
                    if(s1 < s2){
                        p1++;
                        s1 += a[p1];
                    }else{
                        p2++;
                        s2 += b[p2];
                    }
                }
                ans++;
                if(p1 == n) break;
            }
            cout << ans << "\n";
        }
    }
}   
