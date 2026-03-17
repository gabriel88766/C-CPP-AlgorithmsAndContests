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
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    l--;
    auto solve = [&](int sz){
        ll ans = 0;
        vector<int> cnt(26, 0);
        for(int i=0;i<n;i++){
            ans += cnt[s[i]-'a']++;
            if(i >= sz) cnt[s[i - sz] - 'a']--;
        }
        return ans;
    };
    cout << solve(r) - solve(l) << "\n";
}