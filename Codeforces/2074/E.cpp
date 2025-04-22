#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int query(int a, int b, int c){
    cout << "? " << a << " " << b << " " << c << "\n";
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
        int n;
        cin >> n;
        int a = 1, b = 2, c = 3;
        int ans = query(a, b, c);
        while(ans){
            int v = uniform_int_distribution<int>(1, 3)(rng);
            if(v == 1) a = ans;
            if(v == 2) b = ans;
            if(v == 3) c = ans;
            ans = query(a, b, c);
        }
        cout << "! " << a << " " << b << " " << c << "\n";
        cout.flush();
    }
}