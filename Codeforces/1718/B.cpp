#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll f[60];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll maxv = 1e11;
    f[0] = f[1] = 1;
    for(int i=2;f[i-1]+f[i-2] <= maxv;i++){
        f[i] = f[i-1] + f[i-2];
    }
    int mf = 53;
    int t;
    cin >> t;
    while(t--){
        int k;
        bool ok = true;
        cin >> k;
        vector<pair<ll,ll>> v(k);
        ll sum = 0;
        for(int i=0;i<k;i++){
             cin >> v[i].first;
             sum += v[i].first;
             v[i].second = i;
        }
        ll sum2 = 0;
        int x=-1;
        for(int i=0; ; i++){
            sum2 += f[i];
            if(sum2 >= sum){
                if(sum2 == sum){
                    x = i;
                    break;
                }else{
                    ok = false;
                    break;
                }
            }
        }
        sort(v.begin(), v.end(), greater<pair<ll,ll>>());

        int li = -1;
        for(int i=x;i>=0;i--){
            if(v[0].second == li){
                if(v.size() == 1){
                    ok = false;
                    break;
                }else swap(v[0], v[1]);
            }
            if(v[0].first >= f[i]){
                v[0].first -= f[i];
                li = v[0].second;
                sort(v.begin(), v.end(), greater<pair<ll,ll>>());
            }else{
                ok = false;
                break;
            }
        }
        if(v[0].first != 0) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
