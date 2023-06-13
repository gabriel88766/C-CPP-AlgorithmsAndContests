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
    int pot2 = 1;
    while(2*pot2 < n) pot2 *= 2;
    int dif = 0;
    int last = 0;
    while(true){
        cout << "+ " << pot2+dif << "\n";
        cout.flush();
        int val;
        cin >> val;
        if(pot2 == 1){
            if(last != val){
                cout << "! " << val*n << "\n";
                cout.flush();
            }else{
                cout << "! " << (val+1)*n-1 << "\n";
                cout.flush();
            }
            break;
        }else{
            if(last != val){
                dif = n-pot2;
            }else{
                dif = 0;
            }
            pot2/=2;
            last = val;
        }
    }
}
