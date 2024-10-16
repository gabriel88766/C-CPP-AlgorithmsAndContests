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
    int n;
    cin >> n;
    ll cur = 0;
    for(int i=0;i<n;i++){
        int tr;
        cin >> tr;
        for(int j=tr-1;j>=0;j--){
            cur &= ~(1LL << j);
        }
        if(cur & (1LL << tr)){
            cur += 2 * (1LL << tr);
        }else{
            cur += (1LL << tr);
        }
    }
    cout << cur << "\n";
}
