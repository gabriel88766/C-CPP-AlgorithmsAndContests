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
        vector<int> ps1(n+1), ps2(n+1);
        for(int i=0;i<s.size();i++){
            ps1[i+1] = ps1[i];
            ps2[i+1] = ps2[i];
            if(s[i] == '[' || s[i] == ']'){
                if(i % 2) ps1[i+1]++;
                else ps2[i+1]++;
            }
        }
        int q;
        cin >> q;
        while(q--){
            int l, r;
            cin >> l >> r;
            int q1 = ps1[r] - ps1[l-1];
            int q2 = ps2[r] - ps2[l-1];
            cout << abs(q1 - q2) << "\n";
        }
    }
}
