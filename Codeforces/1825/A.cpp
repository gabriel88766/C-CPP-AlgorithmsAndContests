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
        string s;
        cin >> s;
        int n = s.size();
        bool ok = false;
        for(int i=n;i>=1;i--){
            if(ok) break;
            for(int j = 0; j<= n-i; j++){
                bool ok2 = false;
                for(int k=j;k<j+i;k++){
                    if(s[k] != s[i+2*j-k-1]) ok2 = true;
                }
                if(ok2){
                    ok = true;
                    cout << i << "\n";
                    break;
                }
            }
        }
        if(!ok) cout << "-1\n";
    }
}
