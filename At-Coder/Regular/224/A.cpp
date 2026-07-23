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
        ll k;
        cin >> k;
        for(ll i = 1; ; i++){
            string cur = to_string(k * i);
            bool ok = false;
            for(int j=1;j<cur.size();j++){
                if(cur[j] == cur[j-1] && cur[j] == '0'){
                    ok = true;
                    break;
                }
            }
            if(ok){
                cout << k * i << "\n";
                break;
            }
        }
    }
}
