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
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for(int i=1;i<n;i++){
        if(s[i] == 'E') c3++;
        else c4++;
    }
    int ans = INF_INT;
    for(int i=0;i<n;i++){
        ans = min(ans, c3 + c2);
        if(i+1 < n){
            if(s[i+1] == 'E') c3--;
            else c4--;
        }
        if(s[i] == 'E') c1++;
        else c2++;
    }
    cout << ans << "\n";
}
