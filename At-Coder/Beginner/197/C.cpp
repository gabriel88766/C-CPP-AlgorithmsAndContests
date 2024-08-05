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
    int ans =  1 << 30;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<(1 << n);i++){
        if(!(i & (1 << (n-1)))) continue;
        int curi = 0, curj = 0;
        for(int j=0;j<n;j++){
            curj |= v[j];
            if(i & (1 << j)){
                curi ^= curj;
                curj = 0;
            }
        }
        ans = min(ans, curi);
    }
    cout << ans << "\n";
}
