#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int pos[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        pos[x] = i;
    }
    bool ok = true;
    int l = pos[n], r = pos[n];
    for(int i=n-1;i>=1;i--){
        if(pos[i] == l-1) --l;
        else if(pos[i] == r+1) ++r;
        else{
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
