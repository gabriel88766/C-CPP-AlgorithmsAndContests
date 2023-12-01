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
    map<int,int> mp;
    int n;
    string s;
    cin >> n >> s;
    mp[0] = -1;
    int cur = 0, ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '1') cur++;
        else cur--;
        if(mp.count(cur)) ans = max(ans, i-mp[cur]);
        else mp[cur] = i;
    }
    cout << ans << "\n";
}
