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
    //freopen("in", "r", stdin); //test input
    int n;
    int c2 = 0, c1 = 0, c0 = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        if(aux % 2) c0++;
        else if(aux % 4) c1++;
        else c2++;
    }
    if(c2 >= c0) cout << "Yes\n";
    else if(c2 == (c0-1) && c1 == 0) cout << "Yes\n";
    else cout << "No\n";
}
