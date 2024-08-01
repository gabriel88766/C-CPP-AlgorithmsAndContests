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
        vector<string> v(2);
        cin >> v[0] >> v[1];
        int ans = 0;
        for(int i=1;i<n-1;i++){
            for(int p=0;p<2;p++){
                if(v[p][i] == 'x' || v[p^1][i] == 'x') continue;
                if(v[p^1][i-1] == 'x' && v[p^1][i+1] == 'x' && v[p][i-1] == '.' && v[p][i+1] == '.') ans++;
            }
        }
        cout << ans << "\n";
    }
}
