#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
 
    //first sum all non multiples of 2
    //then sum all non multiples of 5 (check all) that are multiple of 2
    ll m = 1e18; //this code was tesded.
    ll n = 1e12 - 10; //this too.
    //ll m = 1e9;
    //ll n = 1e7 - 10;
    ll tt = m - n + 1;

    ll nans = 0;
    cout << 64-__builtin_clzll(m) << " " << __builtin_popcountll(n) << "\n";
    /*for(int i=2;i<=999'999'999;i++){
        ll x = 1;
        ll aux = i;
        while(aux){
            x *= ((aux % 7)+1);
            aux /= 7;
        }
        ans += x;
    }*/
    cout << tt-nans << "\n";
}
 