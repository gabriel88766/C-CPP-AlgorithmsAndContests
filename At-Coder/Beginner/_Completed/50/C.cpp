#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int pot[50010], qt[100000];
void init(int n){
    pot[0] = 1;
    for(int i=1;i<=50005;i++) pot[i] = (pot[i-1] << 1) % MOD;
    for(int i=1;i<=n;i++) qt[max(2*i-n-1, n-2*i+1)]++;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    init(n);
    bool ok = true;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        if(qt[aux] > 0) qt[aux]--;
        else{
            ok = false;
            break;
        }
    }

    if(ok) cout << pot[n/2];
    else cout << 0;
}
