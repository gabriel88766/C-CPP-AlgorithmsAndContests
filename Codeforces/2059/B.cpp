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
        if(n != k){
            //n >= 3
            int tt = n - k + 1;
            bool ok = false;
            for(int i=1;i<=tt;i++){
                if(v[i] != 1) ok = true;
            }
            if(ok) cout << "1\n";
            else cout << "2\n";
        }else{
            for(int i=1;;i++){
                int p = 2*i - 1;
                if(p < n && v[p] == i) continue;
                else{
                    cout << i << "\n";
                    break;
                }
            }
        }
    }
}
