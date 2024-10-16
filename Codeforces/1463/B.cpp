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
        vector<int> v(n+1);
        ll S = 0, Sodd = 0;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(i % 2) Sodd += v[i];
            S += v[i];
        }
        if(2*Sodd > S){
            for(int i=1;i<=n;i++){
                if(i % 2) cout << v[i] << " ";
                else cout << "1 ";
            }
        }else{
            for(int i=1;i<=n;i++){
                if(i % 2) cout << "1 ";
                else cout << v[i] << " ";
            }
        }
        cout << "\n";
    }
}
