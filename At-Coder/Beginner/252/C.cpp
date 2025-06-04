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
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int ans = INF_INT;
    for(char c = '0'; c<='9';c++){
        vector<int> cp(10, 0);
        int val = 0;
        for(int j=0;j<n;j++){
            for(int k=0;k<=9;k++){
                if(v[j][k] == c) cp[k]++;
            }
        }
        for(int k=0;k<=9;k++){
            val = max(val, (cp[k]-1)*10 + k);
        }
        ans = min(ans, val);
    }
    cout << ans << "\n";
}
