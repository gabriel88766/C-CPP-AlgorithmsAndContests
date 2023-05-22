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
        vector<int> mp(26, 0);
        int cnt = 0;
        int n = s.size();
        for(int i=0;i<n/2;i++){
            mp[s[i]-'a']++;
        }
        for(int i=0;i<26;i++) if(mp[i]) cnt++;
        if(cnt >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
}
