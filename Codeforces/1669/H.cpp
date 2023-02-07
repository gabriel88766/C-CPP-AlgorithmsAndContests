#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int pot[31];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    pot[0] = 1;
    for(int i=1;i<=30;i++) pot[i] = pot[i-1]*2;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> qtp(31, 0);
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            for(int j=0;j<31;j++){
                if(aux & pot[j]) qtp[j]++;
            }
        }
        int ans = 0;
        for(int i=30;i>=0;i--){
            if(k >= (n - qtp[i])){
                k -= (n - qtp[i]);
                ans |= pot[i];
            }
        }
        cout << ans << "\n";
    }
}
