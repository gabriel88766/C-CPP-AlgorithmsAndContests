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
        string a, b;
        cin >> a >> b;
        //assume b, try a
        int sb = b.size(), sa = a.size();
        int ans = sb + sa;
        for(int i=0;i<b.size();i++){
            int p1 = i;
            for(int j=0;j<a.size();j++){
                if(p1 < b.size() && a[j] == b[p1]) p1++;
            }
            int cur = sa + sb - (p1 - i);
            ans = min(ans, cur);
        }
        cout << ans << "\n";
    }
}
