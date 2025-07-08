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
    string s;
    cin >> s;
    ll ans = 0;
    vector<int> cnt(26, 0);
    cnt[s.back()-'a']++;
    for(int i=s.size()-2;i>=0;i--){
        cnt[s[i]-'a']++;
        int tt = s.size() - i;
        if(s[i] == s[i+1]){
            ans += tt - cnt[s[i] - 'a'];
            fill(cnt.begin(), cnt.end(), 0);
            cnt[s[i]-'a'] = tt;
        }
    }
    cout << ans << "\n";
}
