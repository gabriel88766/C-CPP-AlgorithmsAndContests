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
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        if(a > b) cout << "NO\n";
        else{
            int c1 = 0, c2 = 0;
            bool ok = true;
            for(int j=0;j<30;j++){
                if(a & (1 << j)) c1++;
                if(b & (1 << j)) c2++;
                if(c2 > c1) ok = false;
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
