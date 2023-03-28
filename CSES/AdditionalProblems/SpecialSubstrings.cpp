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
    vector<bool> has(26, false);
    for(int i=0;i<s.size();i++) has[s[i]-'a'] = true;
    int cnt = 0;
    vector<int> mp(26);
    for(int i=0;i<26;i++) if(has[i]) mp[i] = cnt++;
    vector<int> v(cnt, 0);
    map<vector<int>, int> mp2;
    mp2[v] = 1;
    ll ans = 0;
    for(int i=0;i<s.size();i++){
        v[mp[s[i]-'a']]++;
        int minv = INF_INT;
        for(int j=0;j<cnt;j++) minv = min(minv, v[j]);
        for(int j=0;j<cnt;j++) v[j] -= minv;
        ans += mp2[v]++;
    }
    cout << ans;
}
