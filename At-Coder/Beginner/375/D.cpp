#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+5;
ll pr[26][N], su[26][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++) pr[j][i] = pr[j][i-1];
        pr[s[i]-'A'][i]++;
    }
    for(int i=n;i>=1;i--){
        for(int j=0;j<26;j++) su[j][i] = su[j][i+1];
        su[s[i]-'A'][i]++;
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++){
            ans += pr[j][i-1] * su[j][i+1];
        }
    }
    cout << ans << "\n";
}
