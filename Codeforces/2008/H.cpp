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
        int n, q;
        cin >> n >> q;
        vector<int> ps(n+1);
        vector<int> ans(n+1);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            ps[x]++;
        }
        for(int i=1;i<=n;i++) ps[i] += ps[i-1];
        for(int i=1;i<=n;i++){
            int lo = 0, hi = i-1;
            while(lo != hi){
                int mid = lo + (hi - lo)/2;
                int cur = 0;
                for(int j=0;j<=n;j+=i){
                    cur += ps[min(j+mid, n)];
                    if(j != 0) cur -= ps[j-1];
                }   
                if(cur >= n/2 + 1) hi = mid;
                else lo = mid + 1;
            }
            ans[i] = lo;
        }
        for(int i=1;i<=q;i++){
            int x;
            cin >> x;
            cout << ans[x] << " ";
        }
        cout << "\n";
    }
}
