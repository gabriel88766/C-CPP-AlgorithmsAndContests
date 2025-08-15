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
        vector<int> l(n+1), r(n+1);
        for(int i=1;i<=n;i++){
            if(s[i-1] == 'L'){
                if(i-2 >= 0 && s[i-2] == 'R'){
                    if(i-3 >= 0) l[i] = l[i-2] + 2;
                    else l[i] = 2;
                }else l[i] = 1;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i] == 'R'){
                if(i + 1 < n && s[i+1] == 'L'){
                    if(i+2 < n) r[i] = r[i+2] + 2;
                    else r[i] = 2;
                }else r[i] = 1;
            }
        }
        for(int i=0;i<=n;i++){
            cout << l[i] + r[i] + 1 << " ";
        }
        cout << "\n";
    }
}
