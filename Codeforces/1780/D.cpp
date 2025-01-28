#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
int ask(int x){
    n += x;
    cout << "- " << x << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int b;
        cin >> b;
        n = 0;
        int nb = ask(1);
        int bs;
        if(nb >= b){
            //0 changed to 1
            bs = nb - b + 1;
            b = nb;
        }else{
            //1 changed to 0;
            bs = 0;
            b = nb;
        }

        while(b){
            assert(b != -1);
            if(bs == b){
                n += (1 << bs) - 1;
                break;
            }else{
                nb = ask(1 << bs);
                bs += (nb - b + 1);
                b = nb;
            }
        }
        cout << "! " << n << "\n";
        cout.flush();
    }
}
