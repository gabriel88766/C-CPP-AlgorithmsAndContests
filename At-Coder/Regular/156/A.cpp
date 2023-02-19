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
        string s;
        cin >>n >> s;
        int qt = 0;
        vector<int> ind, ind0;
        for(int i=0;i<n;i++){
             if(s[i] == '1'){
                qt++;
                ind.push_back(i);
             }else ind0.push_back(i);
        }
        if(qt == 2){
            if(ind[0] == (ind[1]-1)){
                bool ok = false;
                for(auto u : ind0){
                    if(abs(u-ind[0]) >= 2 && abs(u-ind[1]) >= 2) ok = true;
                }
                if(n == 3 && !ok) cout << "-1\n";
                else if(!ok) cout << "3\n";
                else cout << "2\n";
            }else cout << "1\n";
        }else if(!(qt%2)) cout << qt/2 << "\n";
        else cout << "-1\n";
    }
}
