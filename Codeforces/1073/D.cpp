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
    ll ans = 0, T;
    int n;
    cin >> n >> T;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    while(T){
        vector<int> b(n, 0);
        ll aux = T, cnt = 0;
        for(int i=0;i<n;i++){
            if(aux >= v[i]){
                aux -= v[i];
                cnt++;
            }
        }
        if(cnt == 0) break;
        ll qt = (T / (T-aux));
        ans += cnt * qt;
        T -= qt * (T-aux);
    }
    cout << ans << "\n";
}
