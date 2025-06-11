#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 55;
int a[N], b[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
    vector<ll> da1, db1;
    for(int i=1;i*i<=a[1];i++){
        if(a[1] % i == 0){
            da1.push_back(i);
            if(i*i != a[1]) da1.push_back(a[1] / i);
        }
    }
    for(int i=1;i*i<=b[1]; i++){
        if(b[1] % i == 0){
            db1.push_back(i);
            if(i*i != b[1]) db1.push_back(b[1] / i);
        }
    }
    ll ans = 1;
    for(auto &x : da1){
        for(auto &y : db1){
            bool ok = true;
            for(int i=1;i<=n;i++){
                if(a[i] % x == 0 && b[i] % y == 0);//ok
                else if(a[i] % y == 0 && b[i] % x == 0); //ok
                else ok = false; 
            }
            if(ok) ans = max(ans, lcm(x, y));
        }
    }
    cout << ans << "\n";
}
