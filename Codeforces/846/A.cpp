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
    vector<int> v(n);
    int ans = 0;
    for(int i=0;i<n;i++) cin >> v[i];
    //only 0's :
    for(int i=0;i<n;i++) if(v[i] == 0) ans++;
    //at least 1 "1"
    for(int i=0;i<n;i++){
        if(v[i] == 1){
            int cur = 0;
            for(int j=0;j<i;j++) if(v[j] == 0) cur++;
            for(int j=i;j<n;j++) if(v[j] == 1) cur++;
            ans = max(ans, cur);
        }
    }
    cout << ans << "\n";
}
