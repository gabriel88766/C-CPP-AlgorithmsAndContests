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
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        int p1 = 0, p2 = n-1;
        int ans = 0;
        int msk = (1 << 31) - 1;
        while(p1 <= p2){
            ans++;
            if(p1 == p2){
                break;
            }
            int x = v[p1] ^ msk;
            if(x == v[p2]){
                p1++;
                p2--;
            }else if(x < v[p2]) p2--;
            else p1++;
        }
        cout << ans << "\n";
    }
}
