#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        string s;
        cin >> n >> s;
        vector<int> mp(26, 0), mp2(26, 0);
        for(int i=0;i<n;i++) mp[s[i]-'a']++;
        for(int i=0;i<(n-1);i++){
            int a = 0, b = 0;
            mp[s[i]-'a']--;
            mp2[s[i]-'a']++;
            for(int j=0;j<26;j++){
                if(mp[j]) a++;
                if(mp2[j]) b++;
            }
            ans = max(ans, a+b);
        }
        cout << ans << "\n";
    }
}
