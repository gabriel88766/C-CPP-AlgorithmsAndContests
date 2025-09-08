#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int bl[N], pos[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) bl[i] = pos[i] = i;
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        int pl = pos[x];
        if(pl == n) pl--;
        swap(bl[pl], bl[pl+1]);
        swap(pos[bl[pl]], pos[bl[pl+1]]);
    }
    for(int i=1;i<=n;i++) cout << bl[i] << " ";
    cout << "\n";
}
