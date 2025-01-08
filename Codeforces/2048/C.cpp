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
        string s;
        cin >> s;
        int n = s.size();
        s = " " + s;
        int f0 = -1;
        for(int i=1;i<=n;i++){
            if(s[i] == '0'){
                f0 = i;
                break;
            }
        }
        if(f0 == -1){
            cout << 1 << " " << n << " " << 1 << " " << 1 << "\n";
        }else{
            vector<int> cd;
            int sz = n - f0 + 1;
            for(int i=1;i<f0;i++) cd.push_back(i);
            for(int i=0;i<sz;i++){
                vector<int> v0, v1;
                for(auto x : cd){
                    if(s[x + i] == '0') v0.push_back(x);
                    else v1.push_back(x);
                }
                if(s[f0 + i] == '1') v0.swap(v1);
                if(v1.size()) cd = v1;
                else cd = v0;
            }
            cout << 1 << " " << n << " " << cd[0] << " " << cd[0] + sz - 1 << "\n";
        }
    }
}
