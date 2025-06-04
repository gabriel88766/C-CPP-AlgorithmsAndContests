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
    int n;
    cin >> n;
    ll d0 = 1, d1 = 1;  
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        ll n0 = 0, n1 = 0;
        if(s == "OR"){
            n0 = d0;
            n1 = 2*d1 + d0;
        }else{
            n0 = 2*d0 + d1;
            n1 = d1;
        }
        d0 = n0;
        d1 = n1;
    }
    cout << d1 << "\n";
}
