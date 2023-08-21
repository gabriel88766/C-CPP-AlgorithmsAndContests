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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int ans = 0;
        for(int i=0;i<n;i++){
            int lo = v[i], hi = 1000000000, mid;
            while(lo != hi){
                mid = lo + (hi - lo + 1)/2;
                bool ok = false;
                ll s = 0;
                for(int j=i;j<n;j++){
                    int goal = mid - (j-i);
                    if(v[j] >= goal){
                        ok = true;
                        break;
                    }else{
                        s += goal-v[j];
                        if(s > k) break; 
                    }
                }
                if(ok) lo = mid;
                else hi = mid-1;
            }
            ans = max(ans, lo);
        }
        cout << ans << "\n";
    }
}
