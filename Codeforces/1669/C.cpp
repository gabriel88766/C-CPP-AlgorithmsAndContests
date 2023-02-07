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
        int n;
        bool o1 = false, o0 = false, e1 = false, e0 = false;
        cin >> n;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            if(i % 2){
                if(aux % 2) o1 = true;
                else o0 = true;
            }else{
                if(aux % 2) e1 = true;
                else e0 = true;
            }
        }
        if((o1 && o0) || (e0 && e1)) cout << "No\n";
        else cout << "Yes\n";
    }
}
