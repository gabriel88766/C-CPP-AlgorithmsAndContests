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
    vector<int> l(n), r(n);
    int sl = 0, sr = 0;
    for(int i = 0;i<n;i++){
        cin >> l[i] >> r[i];
        sl += l[i];
        sr += r[i];
    }
    int maxv = abs(sl - sr);
    int ans = 0;
    for(int i=0;i<n;i++){
        int cl = sl - l[i] + r[i];
        int cr = sr - r[i] + l[i];
        if(abs(cl - cr) > maxv){
            maxv = abs(cl - cr);
            ans = i+1;
        }
    }
    cout << ans << "\n";
}
