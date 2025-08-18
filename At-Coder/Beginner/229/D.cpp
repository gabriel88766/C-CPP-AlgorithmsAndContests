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
    int k;
    cin >> s >> k;
    int n = s.size();
    s = " " + s;
    vector<int> ps(n+2);
    for(int i=1;i<=n+1;i++){
        ps[i] = ps[i-1];
        if(s[i] == '.') ps[i]++;
    }
    ps[n+1] = INF_INT;
    int p2 = 0;
    int ans = 0;
    for(int i=0;i<=n;i++){
        while(ps[p2+1] - ps[i] <= k) p2++;
        ans = max(ans, p2 - i);
    }
    cout << ans << "\n";
}
