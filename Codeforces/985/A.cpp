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
    int n;
    cin >> n;
    vector<int> v(n/2);
    for(int i=0;i<n/2;i++) cin >> v[i];
    int ans = INF_INT;
    sort(v.begin(), v.end());
    for(int b=1;b<=2;b++){
        int cur = 0;
        for(int i=0;i<n/2;i++){
            cur += abs(v[i] - (2*i + b));
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}
