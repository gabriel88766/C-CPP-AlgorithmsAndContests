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
        ll n, k;
        cin >> n >> k;
        vector<int> a(n), h(n+1, INF_INT);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> h[i];
        int p1 = 0;
        int maxl = 0;
        for(int i=1;i<=n;i++){
            if(h[i-1] % h[i]){
                int cur = p1, sum = 0;
                for(int j=p1;j<i;j++){
                    sum += a[j];
                    while(sum > k) sum -= a[cur++];
                    maxl = max(j-cur+1, maxl);
                }
                p1 = i;
            }
        }
        cout << maxl << "\n";
    }
}
