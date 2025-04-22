#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, d12, d23, d13;
        cin >> n >> d12 >> d23 >> d13;
        int a, b, c, dab, dac, dbc;
        if(d12 == max({d12, d23, d13})){
            a = 1, b = 2, c = 3;
            dab = d12;
            dac = d13;
            dbc = d23;
        }else if(d23 == max({d12, d23, d13})){
            a = 2, b = 3, c = 1;
            dab = d23;
            dac = d12;
            dbc = d13;
        }else{
            a = 1, b = 3, c = 2;
            dab = d13;
            dac = d12;
            dbc = d23;
        }

        bool sc = false;
        if(dab > dac + dbc) cout << "NO\n";
        else if(dab == dac + dbc){
            vector<int> aux;
            int aux2 = 4;
            aux.push_back(a);
            while(--dab && --dac){
                aux.push_back(aux2++);
            }
            aux.push_back(c);
            while(--dab) aux.push_back(aux2++);
            aux.push_back(b);
            cout << "YES\n";
            for(int i=1;i<aux.size();i++){
                cout << aux[i-1] << " " << aux[i] << "\n";
            }
            for(int i=aux2;i<=n;i++) cout << aux[0] << " " << i << "\n";
        }else if((dac + dbc - dab) % 2 == 0 && (dab + dac + dbc)/2 <= n-1){
            cout << "YES\n";
            int x = (dac + dbc - dab)/2;
            vector<int> vx;
            int aux2 = 4;
            vx.push_back(a);
            while(--dab){
                vx.push_back(aux2++);
            }
            vx.push_back(b);
            vector<int> vy;
            for(int i=1;i<vx.size();i++){
                if(i + x == dac){
                    vy.push_back(vx[i]);
                }
            }
            while(--x){
                vy.push_back(aux2++);
            }
            for(int i=aux2;i<=n;i++) cout << vx[0] << " " << i << "\n";
            vy.push_back(c);
            for(int i=1;i<vx.size();i++){
                cout << vx[i-1] << " " << vx[i] << "\n";
            }
            for(int i=1;i<vy.size();i++){
                cout << vy[i-1] << " " << vy[i] << "\n";
            }
        }else cout << "NO\n";
    }
}
