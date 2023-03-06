#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int up[26], low[26];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        for(int i=0;i<26;i++) up[i] = low[i] = 0;
        string s;
        int n, k;
        cin >> n >> k >> s;
        for(int i=0;i<n;i++){
            if(s[i] >= 'A' && s[i] <= 'Z') up[s[i]-'A']++;
            else low[s[i]-'a']++;
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            ans += min(up[i], low[i]);
            if(abs(low[i] - up[i])){
                ans += min(k, abs(low[i]-up[i])/2);
                k -= min(k, abs(low[i]-up[i])/2);
            }
        }
        cout << ans << "\n";
    }
}
