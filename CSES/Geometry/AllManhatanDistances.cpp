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
    __int128 ans = 0;
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll psx = 0, psy = 0;
    for(ll i=0;i<n;i++){
        ans += i * x[i] - psx;
        ans += i * y[i] - psy;
        psx += x[i];
        psy += y[i]; 
    }
    string s;
    while(ans){
        s += (ans % 10) + '0';
        ans /= 10;
    }
    reverse(s.begin(), s.end());
    if(!s.size()) s = "0";
    cout << s << "\n";
}
