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
        ll a, b, r;
        cin >> a >> b >> r;
        if(a == b){
            cout << "0\n";
        }else{
            int msb = 60;
            for(int i=60;;i--){
                assert(i >= 0);
                ll aux = 1LL << i;
                if((aux & a) != (aux & b)){
                    msb = i;
                    if((aux & b) != 0) swap(a, b);
                    break;
                }
            }
            ll x = 0;
            for(int i=msb-1;i>=0;i--){
                ll aux = 1LL << i;
                if((aux & a) != 0 && (aux & b) == 0 && (x | aux) <= r){
                    x |= aux;
                }
            }
            cout << abs((a^x) - (b^x)) << "\n";
        }
    }
}   
