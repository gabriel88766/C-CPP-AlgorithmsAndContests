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
        string s;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            char c;
            cin >> c;
            s += c;
        }
        int cnt = 0;
        int ans = 0;
        for(auto c : s){
            if(c == '0') cnt++;
            else{
                if(cnt != 0) ans += (cnt+1)/(k+1);
                cnt = 0;
            }
        }
        if(cnt) ans += (cnt+1)/(k+1);
        cout << ans << "\n";
    }
}
//k -> 1
//k+1 -> 1
//2*k + 1 -> 2
//cnt + 1 / k+1