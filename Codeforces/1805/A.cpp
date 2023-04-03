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
        bool ok = false;
        for(int i=0;i<(1 << 8); i++){
            vector<int> b(n);
            for(int j=0;j<n;j++) b[j] = a[j] ^ i;
            int res = 0;
            for(int j=0;j<n;j++) res ^= b[j];
            if(res == 0){
                cout << i << "\n";
                ok = true;
                break;
            }
        }
        if(!ok) cout << "-1\n";
    }
}
