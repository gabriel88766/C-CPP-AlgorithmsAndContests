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
        ll maxodd = -INF_LL, maxeven = -INF_LL;
        for(int i=0;i<n;i++){
            ll cur;
            cin >> cur;
            
            if(i % 2){
                if(maxodd < 0 && maxodd < cur) maxodd = cur;
                else maxodd = max(maxodd, cur+maxodd);
            }else{
                if(maxeven < 0 && maxeven < cur) maxeven = cur;
                else maxeven = max(maxeven, cur+maxeven);
            }
        }
        cout << max(maxeven, maxodd) << "\n";
        
        
    }
}
