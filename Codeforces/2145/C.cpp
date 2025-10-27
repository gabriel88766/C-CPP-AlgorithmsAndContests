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
        int n;
        cin >> n >> s;
        int val = 0;
        for(auto c : s){
            if(c == 'a') val++;
            else val--;
        }
        int ans = n;
        map<int, int> mp;
        mp[0] = -1;
        int cv = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'a') cv++;
            else cv--;
            mp[cv] = i;
            if(mp.count(cv - val)) ans = min(ans, i - mp[cv - val]);
        }
        if(ans == n) ans = -1;
        cout << ans << "\n";
    }
}
