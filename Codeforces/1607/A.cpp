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
        string s, x;
        cin >> s >> x;
        int ans = 0;
        vector<int> p(26, 0);
        for(int i=0;i<s.size();i++){
            p[s[i]-'a'] = i;
        }
        for(int i=1;i<x.size();i++){
            ans += abs(p[x[i]-'a'] - p[x[i-1]-'a']);
        }
        cout << ans << "\n";
    }
}
