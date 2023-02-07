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
        cin >> n;
        vector<int> ans;
        int xo = 0, xe = 0;
        for(int i=1;i<=(n-2);i++){
            ans.push_back(i);
            if(i%2) xo ^= i;
            else xe ^= i;
        }
        int aux = 1 << 20;
        if(xe == xo){
            ans[0] += aux;
            xo ^= aux;
            aux <<= 1;
            ans.push_back(aux);
            ans.push_back(xo^xe^aux);
        }else{
            ans.push_back(aux);
            ans.push_back(xo^aux^xe);
        }
        for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
