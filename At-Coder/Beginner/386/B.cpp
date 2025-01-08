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
    string s;
    cin >> s;
    int l0 = -1;
    int ans = 0;
    for(int i=0;i<s.size();i++){
        int d = s[i] - '0';
        if(d != 0) ans++, l0 = -1;
        else if(l0 == -1){
            l0 = 0;
            ans++;
        }else{
            l0 = -1;
        }
    }
    cout << ans << "\n";
}
