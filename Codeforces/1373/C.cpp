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
        string s;
        cin >> s;
        int mn = 0, cur = 0;
        ll ans = s.size();
        s = " " + s;
        for(int i=1;i<s.size();i++){
            if(s[i] == '-') cur--;
            else cur++;
            if(cur < mn){
                ans += i;
                mn = cur;
            }
        }
        cout << ans << "\n";
    }
}       
