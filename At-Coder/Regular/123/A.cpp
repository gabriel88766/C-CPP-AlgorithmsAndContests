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
    ll a, b, c;
    cin >> a >> b >> c;
    ll d1 = b - a;
    ll d2 = c - b;
    //operations.
    //d1--; //if d1 > d2 do either this
    //d2++; //or this
    //d1++, d2--; //if d1 < d2, do  (dif+1)/2 + dif % 2
    if(d1 > d2){
        cout << d1-d2 << "\n";
    }else{
        ll dif = d2 - d1;
        cout << (dif + 1)/2 + (dif % 2) << "\n";
    }
}
