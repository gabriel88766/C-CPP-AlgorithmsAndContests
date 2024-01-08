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
        int n;
        cin >> n;
        if(n % 2){
            for(int i=0;i<n;i++) cout << 3 << " ";
            cout << "\n";
        }else{
            //the same, but a1 xor a2 = (a1 + a2)/2 = a3 = a4 = ... an
            cout << 1 << " " << 3 << " ";
            for(int i=2;i<n;i++) cout << 2 << " ";
            cout << "\n";
        }
    }
}
