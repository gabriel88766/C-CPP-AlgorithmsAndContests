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
        int f1 = -1, l1 = -1, c = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                if(f1 == -1) f1 = i;
                l1 = i;
                c++;
            }
        }
        if(c % 2) cout << "NO\n";
        else if(f1 != l1 - 1) cout << "YES\n";
        else cout << "NO\n";

    }
}
