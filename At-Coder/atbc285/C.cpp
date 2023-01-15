#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s;
    cin >> s;
    ll ans = 0;
    ll aux = 1;
    for(int i=(s.size()-1); i>=0; i--){
        ans += aux * (s[i] - 'A' + 1); 
        aux *= 26;
    }
    cout << ans;
}
