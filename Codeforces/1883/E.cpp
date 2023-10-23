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
        ll ans = 0, ln = 0;
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(i == 0) continue;
            if(v[i] > v[i-1]){
                int ind = 0;
                for(int j=0;j<30;j++){
                    if((v[i-1] << (j+1)) > v[i]){
                        ind = j;
                        break;
                    } 
                }
                ln = max(0LL, ln-ind);
            }else{
                int ind = 0;
                for(int j=0;j<30;j++){
                    if((v[i] << j) >= v[i-1]){
                        ind = j;
                        break;
                    } 
                }
                ln += ind;
            }
            ans += ln;
        }
        cout << ans << "\n";
    }
}
