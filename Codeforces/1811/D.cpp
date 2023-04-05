#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll F[50];

bool check(ll x, ll y, ll n){
    if( y >= 1 && y <= F[n+1] && x >= 1 && x <= F[n]) return true;
    else return false;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    F[0] = 1;
    F[1] = 1;
    for(int i=2;i<=45;i++){
        F[i] = F[i-1] + F[i-2];
    }
    while(t--){
        ll n, x, y;
        cin >> n >> x >> y;
        bool ok = true;
        for(int i=n-1;i>=1;i--){
            if(check(y,x,i)){
                swap(x,y);
                continue;
            }
            if(check(F[i+2]-y+1, x, i)){
                ll aux = F[i+2]-y+1;
                y = x;
                x = aux;
                continue;
            }
            ok = false;
            break;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}   
