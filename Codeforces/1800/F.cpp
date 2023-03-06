#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
bool has[N][26];
int mask[N];
int mp[1<<26];
const int maxmask = (1 << 26) - 1;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++){
            has[i][s[j]-'a'] = true;
            mask[i] ^= (1 << (s[j]-'a'));
        }
    }
    ll ans = 0;
    for(int i=0;i<26;i++){
        for(int j=1;j<=n;j++) if(!has[j][i]) mp[mask[j]]++;
        
        for(int j=1;j<=n;j++) if(!has[j][i]){
            int cur = (mask[j] ^ maxmask) & ~(1 << i);
            ans += mp[cur];
        }
        for(int j=1;j<=n;j++) if(!has[j][i]) mp[mask[j]]--;
    }
    cout << ans/2;
    
}
