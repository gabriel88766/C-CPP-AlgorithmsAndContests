#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char ask(int n){
    cout << "? " << n << "\n";
    cout.flush();
    char c;
    cin >> c;
    return c;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    char c2 = ask(n);
    char c1 = ask(1);
    if(c1 == c2) cout << "! " << n << "\n";
    else{
        int l = 1, r = n;
        while(r - l > 1){
            int m = (r + l) / 2;
            char c3 = ask(m);
            bool isl = false;
            if(l % 2 == m % 2){
                if(c1 != c3){
                    isl = true;
                }
            }else{
                if(c1 == c3){
                    isl = true;
                }
            }
            if(isl){
                r = m;
                c2 = c3;
            }else{
                l = m;
                c1 = c3;
            }
        }
        cout << "! " << l << "\n";
    }
    cout.flush();
}
