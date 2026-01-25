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
        vector<bool> num(n+1, false);
        vector<int> dst(n+1, INF_INT);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            num[x] = true;
            dst[x] = 1;
        }
        for(int i=1;i<=n;i++){
            if(dst[i] != INF_INT){
                cout << dst[i] << " ";
                for(int j=2;i*j<=n;j++){
                    if(num[j] && dst[i*j] > dst[i] + 1){
                        dst[i*j] = dst[i] + 1;
                    }
                }
            }else cout << "-1 ";
        }
        cout << "\n";
        
    }
}
