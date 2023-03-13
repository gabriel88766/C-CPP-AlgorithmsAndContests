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
    int t;
    cin >> t;
    while(t--){
        int m, s;
        cin >> m >> s;
        vector<bool> is(51, false);
        int maxv = 0;

        for(int i=0;i<m;i++){
            int aux;
            cin >> aux;
            maxv = max(aux, maxv);
            is[aux] = true;
        }
        bool ok = true;

        for(int i=1;i<=maxv;i++){
            if(!is[i]){
                if(s >= i) s-=i;
                else{
                    ok = false;
                    s = 0;
                    break;
                }
            }
        }
        while(s){
            if(s >= (maxv+1)){
                maxv++;
                s -= maxv;
            }else{
                ok = false;
                break;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}   
