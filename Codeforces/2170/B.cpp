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
        vector<int> v(n);
        ll s = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            s += v[i];
        }
        sort(v.begin(), v.end());
        int ans = 0;
        ll aux = 0;
        for(int i=0;i<n;i++){
            if(v[i] > 0){
                if(aux + 1 <= s - n + 1){
                    aux += 1;
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}
