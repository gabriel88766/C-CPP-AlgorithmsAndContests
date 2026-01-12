#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<100005> bs;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    bs[0] = 1;
    int n;
    cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        bs |= bs << x;
        sum += x;
    }
    int ans = sum;
    for(int j=0;j<=sum;j++){
        if(bs[j]){
            ans = min(ans, max(j, sum - j));
        }
    }
    cout << ans << "\n";

}
