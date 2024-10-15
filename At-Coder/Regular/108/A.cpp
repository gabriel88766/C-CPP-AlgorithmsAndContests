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
    ll s, p;
    cin >> s >> p;
    __int128 aux = s;
    aux *= s;
    aux -= 4*p;
    if(aux < 0) cout << "No\n";
    else{
        __int128 sqt = 0;
        for(__int128 j = s;j>=1;j>>=1){
            while((sqt + j) * (sqt+j) <= aux) sqt += j;
        }
        if(sqt*sqt == aux) cout << "Yes\n";
        else cout << "No\n";
    }
}   
