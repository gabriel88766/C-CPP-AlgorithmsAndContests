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
    ll A, B;
    cin  >> A >> B;
    ll ans = 0;
    while(A != B){
        if(A > B){
            ans += (A-B)/B;
            A -= ((A-B)/B)*B;
            if(A > B){
                A -= B;
                ans++;
            }
        }else{
            ans += (B-A)/A;
            B -= ((B-A)/A)*A;
            if(A < B){
                B -= A;
                ans++;
            }
        }
    }
    cout << ans;
}
