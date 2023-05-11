#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll ps[2002][2002];
pair<int,int> num[1000001];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll aux = 1;
    for(ll i=1;i<=2000;i++){
        for(ll j=aux; j < aux+i; j++){
            if(j > 1000000) break;
            num[j] = {i, j-aux+1};
            ps[i][j-aux+1] = ps[i][j-aux] + j*j;
        }
        aux += i;
        if(aux > 1000000) break;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int l = num[n].second;
        int r = l;
        ll ans = 0;
        for(int i=num[n].first;i>=1;i--){
            ans += ps[i][r] - ps[i][l-1];
            l--;
            l = max(l, 1);
            r = min(r, i-1);
        }
        cout << ans << "\n";
    }
}
