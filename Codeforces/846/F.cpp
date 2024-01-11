#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
vector<int> oc[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    ll tt = n*n;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        oc[aux].push_back(i);
    }
    ll ans = 0;
    for(int i=1;i<N;i++){
        if(oc[i].size()){
            ll cur = tt;
            for(int j=0;j<oc[i].size();j++){
                if(j == 0){
                    ll aux = oc[i][j] - 1;
                    cur -= aux * aux;
                }else{
                    ll aux = oc[i][j] - oc[i][j-1] - 1;
                    cur -= aux*aux;
                }
                if(j == oc[i].size() - 1){
                    ll aux = n-oc[i][j];
                    cur -= aux*aux;
                }
            }
            ans += cur;
        }
    }
    double p = ans;
    p /= tt;
    cout << setprecision(10) << fixed << p << "\n";
}
