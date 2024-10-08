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
        int n, m, k;
        cin >> n >> m >> k;
        int v = (n*m)/2 - k;
        if(n % 2){ //m even
            if(k >= m/2){
                k -= m/2;
                n--;
            }else{
                cout << "NO\n";
                continue;
            }
        }else if(m % 2){
            if(v >= n/2){
                v -= n/2;
                m--;
            }else{
                cout << "NO\n";
                continue;
            }
        }
        if(k % 2) cout << "NO\n";
        else cout << "YES\n";
    }
}