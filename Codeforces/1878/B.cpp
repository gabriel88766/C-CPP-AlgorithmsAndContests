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
        int a = 2, b = 3;
        cout << a << " " << b << " ";
        for(int i=3;i<=n;i++){
            int ol = a;
            a = b;
            b++;
            while(!((3*b) % (a+ol))) b++;
            cout << b << " ";
        }
        cout << "\n";
    }
}
