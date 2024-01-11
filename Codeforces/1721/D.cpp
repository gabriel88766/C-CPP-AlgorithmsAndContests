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
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        int ans = 0;
        for(int j=29;j>=0;j--){
            int msk = ans | (1 << j);
            vector<int> v1, v2;
            for(int i=0;i<n;i++) v1.push_back(a[i] & msk);
            for(int i=0;i<n;i++) v2.push_back(b[i] & msk);
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end(), greater<int>());
            bool ok = true;
            for(int i=0;i<n;i++){
                if((v1[i] ^ v2[i]) != msk){
                    ok = false;
                    break;
                }
            }
            if(ok) ans = msk;
        }
        cout << ans << "\n";
    }
}
