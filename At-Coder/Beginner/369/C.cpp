#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll sum(ll l, ll r){
    ll ans = r - l + 1;
    ans = (ans * (ans + 1)) / 2;
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> dif(n), v(n);
    dif[0] = INF_INT;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(i != 0) dif[i] = v[i] - v[i-1];
    }
    int bg = 1;
    int difc = dif[1];
    ll ans = n;
    for(int i=2;i<n;i++){
        if(difc != dif[i]){
            ans += sum(bg, i-1);
            difc = dif[i];
            bg = i;
        }
    }
    ans += sum(bg, n-1);
    cout << ans << "\n";
}
