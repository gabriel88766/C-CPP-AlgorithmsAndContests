#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int f(ll a){
    int diga = 0;
    while(a){
        diga++;
        a/=10;
    }
    return diga;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n;
    cin >> n;
    int mindig = f(n);
    for(ll i = 1; i<=100000;i++){
        if(!(n%i)){
            mindig = min(mindig, max(f(i), f(n/i)));
        }
    }
    cout << mindig << "\n";
}
