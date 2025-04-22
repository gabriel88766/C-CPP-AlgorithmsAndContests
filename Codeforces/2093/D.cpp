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
        int n, q;
        cin >> n >> q;
        while(q--){
            string qt;
            cin >> qt;
            if(qt == "->"){
                int x, y;
                cin >> x >> y;
                x--, y--;
                ll d = 1;
                for(int l=n-1;l>=0;l--){
                    ll cd = 1LL << (2*l);
                    ll jp = 1LL << l;
                    if(x >= jp && y >= jp){
                        x -= jp;
                        y -= jp;
                        d += cd;
                    }else if(x >= jp){
                        x -= jp;
                        d += 2*cd;
                    }else if(y >= jp){
                        y -= jp;
                        d += 3*cd;
                    }
                }
                cout << d << "\n";
            }else{
                ll d;
                cin >> d;
                d--;
                ll x = 1, y = 1;
                for(int l=n-1;l>=0;l--){
                    ll cd = 1LL << (2*l);
                    ll jp = 1LL << l;
                    if(d / cd == 1){
                        x += jp;
                        y += jp;
                    }else if(d / cd == 2){
                        x += jp;
                    }else if(d / cd == 3){
                        y += jp;
                    }
                    d -= (d / cd) * cd;
                }
                cout << x << " " << y << "\n";
            }
        }
    }
}
