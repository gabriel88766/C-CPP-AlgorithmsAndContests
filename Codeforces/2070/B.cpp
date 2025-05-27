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
        ll n, x, k;
        cin >> n >> x >> k;
        string s;
        cin >> s;
        ll m1 = 0;
        for(auto &c : s){
            if(c == 'L') x--;
            else x++;
            m1++;
            if(x == 0){
                break;
            }
        }
        if(x != 0) cout << "0\n";
        else{
            int m2 = 0;
            for(auto &c : s){
                if(c == 'L') x--;
                else x++;
                m2++;
                if(x == 0){
                    break;
                }
            }
            if(x == 0){
                //then repeat..
                ll ans = 1 + (k-m1)/m2;
                cout << ans << "\n";
            }else{
                if(k >= m1) cout << "1\n";
                else cout << "0\n";
            }
        }
    }
}
