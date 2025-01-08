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
        int n, m, k;
        string ans;
        cin >> n >> m >> k;
        vector<int> a(m), b(k);
        for(int i=0;i<m;i++) cin >> a[i];
        for(int i=0;i<k;i++) cin >> b[i];
        if(k == n){
            ans = string(m, '1');
        }else if(k == n-1){
            vector<bool> is(n+1, false);
            for(int i=0;i<k;i++) is[b[i]] = true;
            int id = -1;
            for(int i=1;i<=n;i++) if(!is[i]) id = i;
            ans = string(m, '0');
            for(int i=0;i<m;i++){
                if(a[i] == id) ans[i] = '1';
            }
        }else{
            ans = string(m, '0');
        }
        cout << ans << "\n";
    }
}
