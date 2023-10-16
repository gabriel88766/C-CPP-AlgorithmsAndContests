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
        bool h1 = false, h0 = false;
        vector<int> v1, v0;
        cin >> s;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                h1 = true;
                v1.push_back(i);
            }else if(s[i] == '0'){
                h0 = true;
                v0.push_back(i);
            }
        }
        if(!h0 && !h1) cout << n << "\n";
        else if(h0 && !h1){
            cout << v0[0] + 1 << "\n";
        }else if(!h0 && h1){
            cout << n-v1.back() << "\n";
        }else{
            cout << v0[0]-v1.back()+1 << "\n";
        }
    }
}
