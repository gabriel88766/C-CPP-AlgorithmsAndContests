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
    string s;
    cin >> n >> s;
    ll ans = 0;
    ll cnt = 0;
    char lc = '.';
    s += '$';
    for(int i=0;i<=n;i++){
        if(s[i] == lc) cnt++;
        else{
            ans += (cnt * (cnt-1))/2;
            cnt = 1;
            lc = s[i];
        }
    }
    cout << ans << "\n";
}
