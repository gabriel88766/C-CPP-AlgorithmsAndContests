#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll func(ll n){
    string s = to_string(n);
    string t = s;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());
    return stol(t) - stol(s);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    cin >> n >> k;
    for(int i=0;i<k;i++){
        n = func(n);
    }
    cout << n << "\n";
}
