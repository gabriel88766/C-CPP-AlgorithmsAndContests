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
    if(n < 1000){} //do nothing
    else if(n < 10000) n -= n%10;
    else if(n < 100000) n -= n%100;
    else if(n < 1000000) n -= n%1000;
    else if(n < 10000000) n -= n%10000;
    else if(n < 100000000) n -= n%100000;
    else n -= n%1000000;
    cout << n;
}
