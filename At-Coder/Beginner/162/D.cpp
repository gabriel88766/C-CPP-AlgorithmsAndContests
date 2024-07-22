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
    ll ans = 0;
    for(int i=0;i<n;i++){
        int rl=0,gl=0,bl=0,rr=0,gr=0,br=0;
        for(int j=0;j<i;j++){
            if(s[j] == 'R') rl++;
            else if(s[j] == 'G') gl++;
            else bl++;
        }
        for(int j=i+1;j<n;j++){
            if(s[j] == 'R') rr++;
            else if(s[j] == 'G') gr++;
            else br++;
        }
        if(s[i] == 'R') ans += gl*br + gr*bl;
        else if(s[i] == 'G') ans += rl*br + rr*bl;
        else ans += rl*gr + rr*gl;
        for(int j=1;;j++){
            if(i-j >= 0 && i+j < n){
                if(s[i] != s[i-j] && s[i] != s[i+j] && s[i-j] != s[i+j]) ans--;
            }else break;
        }
    }
    cout << ans << "\n";
}
