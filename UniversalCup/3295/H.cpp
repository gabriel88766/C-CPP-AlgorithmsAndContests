
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
    int k, n;
    cin >> k >> n;
    int mx = -INF_INT;
    for(int i=1;i<=k;i++){
        int x;
        cin >> x;
        mx = max(x, mx);
    }
    double ans = 0;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int k2 = k - 1;
    double pr2 = 1.0 / n;
    double sum = 0;
    pr2 *= k2;
    for(int i=n-1;i>=k2-1;i--){ 
        double st1 = i >= 0 ? max(mx, v[i]) : mx; 
        double st2 = (i == -1 ? 0 : v[i] * double(i + 1 - k2) / (n - k2)) + sum / (n - k2);
        ans += max(st1, st2) * pr2;
        if(i == 0){
            pr2 = 1; //corner case, k2 = 0
        }else{
            pr2 /= i;
            pr2 *= (i - k2 + 1);
        }
        sum += v[i];
    }
    cout << setprecision(10) << fixed << ans << "\n";
}
