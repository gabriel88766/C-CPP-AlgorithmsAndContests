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
        ll n, l, r;
        cin >> n >> l >> r;
        ll bx = 1, by = 2;
        ll qt = (l-1)/2;
        while(qt){
            if(qt >= n - bx){
                qt -= n - bx;
                bx++;
                by = bx + 1;
            }else{
                by = bx + 1 + qt;
                break;
            }
        }
        if(by > n){
            cout << "1\n";
        }else{
            for(ll i=l;i<=r;i++){
                if(i % 2){
                    cout << bx << " ";
                }else{
                    cout << by << " ";
                    by++;
                    if(by > n){
                        bx++;
                        by = bx + 1;
                        if(bx == n) bx = 1;
                    }
                }
            }
            cout << "\n";
        }


    }
}   
