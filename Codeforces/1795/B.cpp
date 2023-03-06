#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int bg[51], eend[51];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        memset(bg, 0, sizeof(bg));
        memset(eend, 0, sizeof(eend));
        for(int i=1;i<=n;i++){
            int a, b;
            cin >> a >> b;
            bg[a]++;
            eend[b]++;
        }
        if(bg[k] && eend[k]) cout << "YES\n";
        else cout << "NO\n";
    }
}
