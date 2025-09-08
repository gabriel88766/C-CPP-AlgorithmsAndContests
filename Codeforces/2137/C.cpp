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
        ll a, b;
        cin >> a >> b;
        if(a % 2 == 1 && b % 2 == 1){
            //both odd
            cout << a*b + 1 << "\n";
        }else{
            if(b % 2 != 0) cout << "-1\n";
            else{
                assert((a * b) % 2 == 0);
                ll aa = (a * b) / 2, bb = 2;
                if(aa % 2 == 0) cout << aa + bb << "\n";
                else cout << "-1\n";
            }
        }
    }
}
