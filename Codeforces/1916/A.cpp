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
        ll res = 1;
        for(int i=0;i<n;i++){
             cin >> v[i];
             res *= v[i];
        }
        if(res <= 2023 && !(2023 % res)){
            cout << "YES\n";
            cout << 2023/res << " ";
            for(int i=1;i<k;i++) cout << 1 << " ";
            cout << "\n";
        }else cout << "NO\n";

    }
}
