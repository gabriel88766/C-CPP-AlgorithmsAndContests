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
        bool f01 = false;
        int ans = 0;
        for(int i=1;i<s.size();i++){
            if(s[i] != s[i-1]) ans++;
            if(s[i] == '1' && s[i-1] == '0') f01 = true;
        }
        if(f01) ans--;
        cout << ans+1 << "\n";
    }
}
