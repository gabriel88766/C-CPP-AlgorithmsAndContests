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
    int x = 0, y = 0, t = 0;
    bool ok = true;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> c >> a >> b;
        int dx = abs(a-x);
        int dy = abs(b-y);
        t += (dx + dy);
        x = a, y = b;
        if(c < t || (c-t) % 2){
            ok = false;
        }
        t = c;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
