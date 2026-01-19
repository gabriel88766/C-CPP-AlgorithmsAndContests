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
        ll n;
        cin >> n;
        for(ll i=2;;i++){
            if(n % i == 0){
                if(n % (i*i) == 0){
                    cout << i << " " << n / (i*i) << "\n";
                }else{
                    ll sqt = sqrt(n / i);
                    while(sqt*sqt > (n/i)) sqt--;
                    while(sqt*sqt < (n/i)) sqt++;
                    cout << sqt << " " << i << "\n";
                }
                break;
            }
        }
    }
}
