#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ask(int n){
    if(n == 0) return true;
    cout << "? " << n << "\n";
    cout.flush();
    string ans;
    cin >> ans;
    return ans == "YES";
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int ans = 0;
    for(int i=29;i>=0;i--){
        int jmp = 1 << i;
        if(ask(ans + jmp - 1)) ans += jmp;
    }
    cout << "! " << ans << "\n";
    cout.flush();
}
