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
        cin >> n;
        string a, b;
        cin >> a >> b;
        int ce = 0, co = 0;
        for(int i=0;i<n;i++){
            if(i % 2 == 0){
                if(a[i] == '1') ce--;
                if(b[i] == '0') co++;
            } else{
                if(b[i] == '0') ce++;
                if(a[i] == '1') co--;
            }
        }
        if(ce < 0 || co < 0) cout << "NO\n";
        else cout << "YES\n";
    }
}
