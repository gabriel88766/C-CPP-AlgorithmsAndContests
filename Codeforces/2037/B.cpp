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
        int k;
        cin >> k;
        vector<int> v(k+1);
        int n = k-2;
        for(int i=1;i<=k;i++){
            int x;
            cin >> x;
            v[x]++;
        }
        for(int i=1;i<=n;i++){
            if(n % i) continue;
            if(n/i == i){
                if(v[i] >= 2){
                    cout << i << " " << i << "\n";
                    break;
                }
            }else{
                if(v[i] && v[n/i]){
                    cout << i << " " << n/i << "\n";
                    break;
                }
            }
        }
    }
}
