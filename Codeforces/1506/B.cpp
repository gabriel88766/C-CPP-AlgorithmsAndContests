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
        string s;
        cin >> n >> k >> s;
        int lx;
        int lc = -1000;
        int ans = 0;
        bool ini = false;
        for(int i=0;i<n;i++){
            if(s[i] == '*'){
                lx = i;
                if(ini){
                    if(i - lc > k){
                        ans++;
                        for(int j=i-1;;j--){
                            if(s[j] == '*'){
                                lc = j;
                                break;
                            }
                        }
                    }
                }else{
                    ans++;
                    lc = i;
                    ini = true;
                }
            }
        }
        if(lx != lc) ans++;
        cout << ans << "\n";
    }
}
