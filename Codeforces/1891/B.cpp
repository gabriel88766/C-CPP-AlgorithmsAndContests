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
        vector<int> v(n);
        vector<int> divs = {35};
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        for(int i=0;i<q;i++){
            int aux;
            cin >> aux;
            if(aux < divs.back()) divs.push_back(aux);
        }
        for(int i=1;i<divs.size();i++){
            int cur = 1 << divs[i];
            for(int j=0;j<n;j++){
                if(!(v[j] % cur)) v[j] += cur/2;
            }
        }
        for(int i=0;i<n;i++) cout << v[i] << " ";
        cout << "\n";
    }
}
