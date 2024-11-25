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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        if(k != 4){
            int ans = 10;
            for(int i=0;i<n;i++){
                if(v[i] % k) ans = min(ans, k-(v[i]%k));
                else ans = 0;
            }
            cout << ans << "\n";
        }else{
            int ans = 2, c = 0;
            for(int i=0;i<n;i++){
                if(!(v[i] % 2)) c++;
                if(!(v[i] % 4)) c++; 
            }
            if(c >= 2) ans = 0;
            else if(c == 1) ans = 1;
            else{
                for(int i=0;i<n;i++){
                    if(v[i] % 4 == 3) ans = 1;
                }
            }
            cout << ans << "\n";
        }
    }
}
