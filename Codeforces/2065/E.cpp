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
        int n, m, k;
        cin >> n >> m >> k;
        if(k <= max(n, m) && k >= abs(n-m)){
            string ans;
            bool sw = false;
            if(m > n){
                sw = true;
                swap(n, m);
            }
            for(int i=0;i<k;i++) ans += '0';
            n -= k;
            bool ism = true;
            while(n > 0 && m > 0){
                if(ism){
                    ans += '1';
                    --m;
                    ism = false;
                }else{
                    ans += '0';
                    --n;
                    ism = true;
                }
            }
            while(m){
                ans += '1';
                m--;
            }
            while(n){
                ans += '0';
                n--;
            }
            if(sw){
                for(auto &x : ans){
                    if(x == '0') x = '1';
                    else x = '0';
                }
            }
            cout << ans << "\n";
            
        }else cout << "-1\n";   
    }
}
