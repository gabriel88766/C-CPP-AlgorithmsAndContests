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
        string x;
        cout << "mul 999999999\n";
        cout.flush();
        cin >> x;
        assert(x == "1");
        cout << "digit\n";
        cout.flush();
        cin >> x;
        assert(x == "1");
        if(n != 81){
            cout << "add " << n-81 << "\n";
            cout.flush();
            cin >> x;
        }
        cout << "!\n";
        cout.flush();
        cin >> x;
    }
}
