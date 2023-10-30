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
    ll n, k;
    cin >> n >> k;
    ll tt = (k*(k-1));
    if(tt >= n){
        cout << "YES\n";
        int i = 1, j = 2;
        while(n--){
            cout << i << " " << j << "\n";
            if(i < j) swap(i, j);
            else{
                swap(i, j);
                if(j+1 <= k) j++;
                else{
                    i++;
                    j = i+1;
                }
            }
        }
    }else cout << "NO\n";
}
