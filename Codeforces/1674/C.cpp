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
        string s, t;
        cin >> s >> t;
        if(t.size() > 1){
            bool ca = false;
            for(int i=0;i<t.size();i++) if(t[i] == 'a') ca = true;
            if(ca) cout << "-1\n";
            else{
                cout << (1LL << s.size()) << "\n";
            }
        }else if(t == "a") cout << "1\n";
        else{
            cout << (1LL << s.size()) << "\n";
        }
    }
}
