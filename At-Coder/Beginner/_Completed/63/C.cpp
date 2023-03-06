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
    int lnm10 = INF_INT;
    int sum = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        if(aux%10){
            if(aux < lnm10) lnm10 = aux;
        }
        sum += aux;
    }
    if((sum % 10)) cout << sum;
    else if(lnm10 < 1000) cout << sum - lnm10;
    else cout << 0;
}
