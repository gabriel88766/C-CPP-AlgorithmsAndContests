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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        if(v[0] != n) cout << "NO\n";
        else{
            vector<int> u(n);
            for(int i=0;i<n;i++){
                int l = i+1;
                int p = 0;
                for(int j=n/2;j >= 1; j/=2){
                    while(p+j < n && v[p+j] >= l) p += j;
                }
                u[i] = p+1;
            }
            if(u == v) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
