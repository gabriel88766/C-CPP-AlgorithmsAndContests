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
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n+1), b(k), cnt(n+1, 0);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=0;i<k;i++) cin >> b[i];
        ll ans = 0;
        for(int i=0;i<=min(d-1, 2*n); i++){
            //do sum i times, and get score i+1;
            ll sc = (d - i - 1)/2;
            auto vec = a;
            int s = i;
            for(int j=1;j<=n;j++){
                vec[j] += s;
                s -= cnt[j];
                if(vec[j] == j) sc++;
            }
            ans = max(ans, sc);
            cnt[b[i%k]]++;
        }
        cout << ans << "\n";
    }   
}