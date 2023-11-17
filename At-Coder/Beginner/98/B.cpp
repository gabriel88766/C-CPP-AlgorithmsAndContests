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
    int ans = 0;
    for(int i=1;i<n;i++){
        string s1 = s.substr(0, i);
        string s2 = s.substr(i, n-i);
        vector<int> c1(26, 0), c2(26, 0);
        for(auto x : s1) c1[x-'a']++;
        for(auto x : s2) c2[x-'a']++;
        int cnt = 0;
        for(int i=0;i<26;i++) if(c1[i] && c2[i]) cnt++;
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}
