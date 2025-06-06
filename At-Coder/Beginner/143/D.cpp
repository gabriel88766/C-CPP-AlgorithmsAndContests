#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> cv[2005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++) cv[i].push_back(v[j]);
        sort(cv[i].begin(), cv[i].end());
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            //given the set > j
            //count < a+b && > b-a
            int a = v[i], b = v[j];
            int mx = a + b;
            int mn = abs(b - a);    

            int dif = lower_bound(cv[j+1].begin(), cv[j+1].end(), mx) - lower_bound(cv[j+1].begin(), cv[j+1].end(), mn+1);
            ans += dif;
            // cout << mn << " " << mx << " " << dif << "\n";
        }
    }
    cout << ans << "\n";
}
