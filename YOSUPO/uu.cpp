#include <bits/stdc++.h>
#pragma GCC optimize("O2")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int ans = 0;
    for(int i=1;i<=1'000'000'000;i++){
        auto x = to_string(i);
        reverse(x.begin(), x.end());
        if(x[0] == '0') continue;
        int n = i + stoi(x);
        bool ok = true;
        while(n){
            int c = n % 10;
            if(c % 2 == 0) ok = false;
            n /= 10;
        }
        if(ok) ans++;
    }
    cout << ans << "\n";
}