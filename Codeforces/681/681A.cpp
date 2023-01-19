#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    char isOk = false;
    cin >> n;
    while(n--){
        string s;
        int a, b;
        cin >> s >> a >> b;
        if(a >= 2400 && b > a) isOk = true;
    }
    if(isOk) cout << "YES";
    else cout << "NO";
}
