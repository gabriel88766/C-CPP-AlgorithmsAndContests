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
        int x, k;
        cin >> x >> k;
        if(k > 1 && x > 1) cout << "NO\n";
        else if(k > 1){
            string num = "";
            for(int i=0;i<k;i++) num += '1';
            int acx = stoi(num);
            bool ok = true;
            for(int i=2;i*i<=acx;i++){
                if(acx % i == 0) ok = false;
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }else{
            bool ok = true;
            if(x == 1 && k == 1) ok = false;
            for(int i=2;i*i<=x;i++){
                if(x % i == 0) ok = false;
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
