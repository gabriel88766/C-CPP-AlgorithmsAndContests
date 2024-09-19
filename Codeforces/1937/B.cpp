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
        string a, b;
        int n;
        cin >> n >> a >> b;
        string ans = "";
        ans += a[0];
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(a[i] == b[i-1]){
                cnt++;
                ans += a[i];
            }else{
                if(a[i] < b[i-1]){
                    cnt = 1;
                    ans += a[i];
                }else{
                    ans += b.substr(i-1, n-(i-1));
                    break;
                }
            }
            if(i == n-1) ans += b.back();
        }
        cout << ans << "\n" << cnt << "\n";
    }
}
