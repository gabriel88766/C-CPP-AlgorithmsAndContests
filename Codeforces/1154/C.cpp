#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int eat[] = {0,0,1,2,0,2,1};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    
    for(int bg=0;bg<7;bg++){
        ll auxa = a, auxb = b, auxc = c;
        ll cura = (auxa/3)*7, curb = (auxb/2)*7, curc = (auxc/2)*7;
        auxa -= (auxa/3)*3, auxb -= (auxb/2)*2, auxc -= (auxc/2)*2;
        for(int j=bg; j <= 1000; j++){
            j = j%7;
            if(auxa>=0 || auxb>=0 || auxc>=0){
                if(auxa >= 0){
                    if(eat[j] == 0) auxa--;
                    if(auxa >= 0) cura++;
                }
                if(auxb >= 0){
                    if(eat[j] == 1) auxb--;
                    if(auxb >= 0) curb++;
                }
                if(auxc >= 0){
                    if(eat[j] == 2) auxc--;
                    if(auxc >= 0) curc++;
                }
            }else break;
        }   
        ll cur = min(cura, min(curb,curc));
        ans = max(ans, cur);
    }
    cout << ans;
}
