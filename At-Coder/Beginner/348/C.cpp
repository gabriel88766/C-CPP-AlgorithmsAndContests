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
    map<int, int> mp;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a, c;
        cin >> a >> c;
        if(!mp.count(c)) mp[c] = a;
        else mp[c] = min(mp[c], a);
    }
    int mx = 0;
    for(auto [a, b] : mp){
        mx = max(mx, b);
    }
    cout << mx << "\n";
}
