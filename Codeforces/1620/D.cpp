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
        for(int i=0;i<n;i++) cin >> a[i];
        int mx = *max_element(a.begin(), a.end());
        int mn = *min_element(a.begin(), a.end());

        if(mx % 3 == 0){
            bool ok = true;
            for(int i=0;i<n;i++){
                if(a[i] % 3 != 0) ok = false;
            }
            if(ok) cout << mx/3 << "\n"; //3 3 3 3 3 3 3
            else cout << mx/3 + 1 << "\n"; //3 3 3 3 3 1 2
        }else if(mx % 3 == 1){
            if(mn == 1){
                bool ok = true;
                for(int i=0;i<n;i++){
                    if(a[i] % 3 == 2) ok = false;
                }
                if(ok) cout << mx/3 + 1 << "\n"; //3 3 3 3 3 3 3 1
                else cout << mx/3 + 2 << "\n"; //3 3 3 3 3 3 3 2 1 1
            }else{
                //corner case : 2 3 4
                //cant make both mx - 1 and % 3 == 2 using 3 3 3 3 ... 2 2
                bool n1 = false, n2 = false;
                for(int i=0;i<n;i++){
                    if(a[i] == mx-1) n1 = true;
                    if(a[i] % 3 == 2) n2 = true;
                }
                if(n1 && n2){ //need 1 and need 2, 3 3 ... 3 2 1 1
                    cout << mx/3 + 2 << "\n";
                }else{
                    cout << mx/3 + 1 << "\n";
                }
                
            }
        }else{
            bool ok = true;
            for(int i=0;i<n;i++){
                if(a[i] % 3 == 1) ok = false;
            }
            if(ok) cout << mx/3 + 1 << "\n"; //3 3 3 3 3 3 3 2
            else cout << mx/3 + 2 << "\n"; //3 3 3 3 3 3 3 3 1 1
        }
    }
}
