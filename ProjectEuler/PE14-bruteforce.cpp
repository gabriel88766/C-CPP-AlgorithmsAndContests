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
    int bst = 1, ans = 1;
    for(int i=2;i<=1'000'000;i++){
        ll cur = i, cnt = 1;
        while(cur != 1){
            if(cur % 2 == 0) cur /= 2;
            else cur = 3*cur + 1;
            cnt++;
        }
        if(cnt > bst){
            bst = cnt;
            ans = i;
        }
    }
    cout << ans << "\n";
}
