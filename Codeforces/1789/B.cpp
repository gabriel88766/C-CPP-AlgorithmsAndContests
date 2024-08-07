#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int fi = -1;
        for(int i=0;i<n/2;i++){
            if(s[i] != s[n-i-1]){
                fi = i;
                break;
            }
        }
        bool ok = true;
        if(fi != -1){
            bool nok = false;
            for(int i=fi;i<n/2;i++){ 
                if(s[i] == s[n-i-1]){
                    fi = i+1;
                    nok = true;
                    break;
                }
            }
            if(nok){
                for(int i=fi;i<n/2;i++) if(s[i] != s[n-i-1]) ok = false;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
