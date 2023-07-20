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
        vector<int> v(101, 0);
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            v[aux]++;
        }
        int ans = 0;
        for(int i=2;i<=100;i++){//all weights
            int cur = 0;
            for(int j=1;2*j<=i;j++){
                int w2 = i-j;
                if(w2 == j) cur += v[j]/2;
                else cur += min(v[j], v[w2]);
            }
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
}
