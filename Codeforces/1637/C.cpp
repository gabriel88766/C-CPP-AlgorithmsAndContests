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
        if(n == 3){
            int x;
            cin >> x;
            cin >> x;
            if(x % 2 == 0) cout << x/2 << "\n";
            else cout << "-1\n";
            cin >> x;
            continue;
        }
        int x;
        cin >> x;
        ll sum = 0;
        bool h2 = false;
        for(int i=2;i<n;i++){
            cin >> x;
            if(x >= 2) h2 = true;
            sum += (x + 1)/2; 
        }
        cin >> x;
        if(h2) cout << sum << "\n";
        else cout << "-1\n";
    }
}
