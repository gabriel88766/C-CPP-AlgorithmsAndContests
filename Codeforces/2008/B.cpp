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
        string s;
        cin >> n >> s;
        bool ok = false;
        for(int i=1;i<=n;i++){
            if(i*i == n){
                int tc = n/i;
                bool cok = true;
                for(int r=0;r<i;r++){
                    for(int c=0;c<tc;c++){
                        if(r == 0 || r == i-1 || c == 0 || c == tc - 1){
                            if(s[r*tc+c] != '1') cok = false;
                        }else if(s[r*tc+c] != '0') cok = false;
                    }
                }
                if(cok) ok = true;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
