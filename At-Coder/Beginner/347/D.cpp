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
    ll a, b, c;
    cin >> a >> b >> c;
    if(__builtin_popcountll(c) <= a + b && __builtin_popcountll(c) % 2 == (a+b) % 2 && a+b-__builtin_popcountll(c) <= 2*(60 - __builtin_popcountll(c))){
        ll x = 0, y = 0;
        int ttb = (a+b-__builtin_popcountll(c))/2;
        for(int j=0;j<60;j++){
            if(c & (1LL << j)){
                if(a > b){
                    a--;
                    x |= (1LL << j);
                }else{
                    b--;
                    y |= (1LL << j);
                }
            }
        }
        if(a != b){
            cout << "-1\n";
        }else{
            
            for(int i=0;i<60;i++){
                if(!(c & (1LL << i))){
                    if(ttb){
                        x |= 1LL << i;
                        y |= 1LL << i;
                        ttb--;
                    }
                }
            }
            cout << x << " " << y << "\n";
        }
    }else cout << "-1\n";
}   
