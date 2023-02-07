#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, wa = 0, wb = 0, wab = 0;
        cin >> n;
        for(int i=1;i<=n;i++){
            int aux;
            cin >> aux;
            if(aux != i) wa++;
            if(aux != (n-i+1)) wb++;
            if(aux != i && aux != (n-i+1)) wab++;
        }
        if((wa - wab) > wb) cout << "Second\n";
        else if(wa < (wb - wab+1)) cout << "First\n";
        else cout << "Tie\n";
    }
}
