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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<double> v(n+2);
        v[n+1] = 2e12;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            v[i] = x;
        }
        if(n == 1){
            cout << "0\n";
            continue;
        }
        int ans = 1;
        double l, r;
        l = v[1] + 0.01;
        r = v[2];
        for(int i=2;i<n;i++){
            double rmn = v[i] - r;
            double rmx = v[i] - l;
            if(v[i] + rmn + 0.01 > v[i+1]){
                l = v[i] + 0.01;
                r = v[i+1];
            }else{
                ans++;
                l = v[i] + rmn;
                r = v[i] + min(rmx, v[i+1] - v[i]);
            }
        }
        cout << ans << "\n";
    }
}