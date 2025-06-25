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
    int c1 = 0, c0 = 0;
    for(auto &c : s){
        if(c == '1') swap(c0, c1);
        else{
            c1 += c0;
            c0 = 0;
        }
        if(c == '1') c1++;
        else c0++;
        ans += c1;
        // cout << ans << " ";
    }
    cout << ans << "\n";
}
