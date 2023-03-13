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
        ll n, m;
        cin >> n >> m;
        ll aux = n;
        ll cnt2 = 0, cnt5 = 0;
        while(!(aux % 2)){
            cnt2++;
            aux /= 2;
        }
        while(!(aux % 5)){
            cnt5++;
            aux /= 5;
        }

        ll k = 1;
        int diff = abs(cnt2-cnt5);
        if(cnt2 > cnt5){
            for(int i=0;i<diff;i++){
                if(k*5 <= m){
                    cnt5++;
                    k *= 5;
                }
            }
        }else if(cnt2 < cnt5){
            for(int i=0;i<diff;i++){
                if(k*2 <= m){
                    cnt2++;
                    k *= 2;
                }
            }
        }
        while(k*10 <= m){
            k *= 10;
        }
        k = (m/k)*k;
        cout << n*k << "\n";
    }
}
