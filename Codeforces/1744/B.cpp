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
        int n, q;
        cin >> n >> q;
        ll se=0, so=0, qte = 0, qto = 0;
        for(int i=1;i<=n;i++){
            int aux;
            cin >> aux;
            if(aux % 2) so += aux, qto++;
            else se += aux, qte++;
        }
        for(int i=0;i<q;i++){
            int x, a;
            cin >> x >> a;
            if(x == 0){
                //all even
                if(a % 2){
                    so += (qte*a + se);
                    qto += qte;
                    qte = 0;
                    se = 0;
                }else{
                    se += (qte*a);
                }
            }else{
                if(a % 2){
                    se += (qto*a + so);
                    qte += qto;
                    qto = 0;
                    so = 0;
                }else{
                    so += (qto * a);
                }
            }
            cout << se + so << "\n";
        }
    }
}
