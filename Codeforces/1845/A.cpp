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
        int n, k, x;
        cin >> n >> k >> x;
        if(x != 1){
            cout << "YES\n" << n << "\n";
            for(int i=0;i<n;i++) cout << "1 ";
            cout << "\n";
        }else if(k == 1) cout << "NO\n";
        else if(k == 2 && n%2) cout << "NO\n";
        else{
            int xx = (n / 2) - (n % 2);
            cout << "YES\n";
            if(n % 2) cout << xx + 1 << "\n";
            else cout << xx << "\n";
            for(int i=0;i<xx;i++) cout << "2 ";
            if(n % 2) cout << "3";
            cout << "\n";
        }
    }
}
