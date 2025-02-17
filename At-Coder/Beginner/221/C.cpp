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
    sort(s.begin(), s.end());
    ll ans = 0;
    do{
        if(s[0] == '0') continue;
        for(int i=1;i<s.size();i++){
            if(s[i] == '0') continue;
            string s1 = s.substr(0, i);
            string s2 = s.substr(i, s.size()-i);
            ll n1 = stoi(s1);
            ll n2 = stoi(s2);
            ans = max(ans, n1 * n2);
        }
    }while(next_permutation(s.begin(), s.end()));
    cout << ans << "\n";
}
