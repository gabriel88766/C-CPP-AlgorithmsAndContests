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
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '/'){
            int p0 = i, p1 = i;
            while(p0-1 >= 0 && p1+1 < n && s[p0-1] == '1' && s[p1+1] == '2') p0--,p1++;
            ans = max(ans, 1 + 2*(i-p0));
        }
    }
    cout << ans  << "\n";
}
