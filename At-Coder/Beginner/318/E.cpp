#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
vector<ll> eq[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        eq[aux].push_back(i);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll S = 0, ttS = 0;
        for(int j=1;j<eq[i].size();j++){
            ll aux = eq[i][j] - eq[i][j-1] - 1;
            S += aux * j;
            ttS += S;
        }
        ans += ttS;
    }
    cout << ans << "\n";
}
