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
    string s;
    cin >> s;
    if(s == "first"){
        int n;
        cin >> n;
        string ans;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            ans += 'a' + x - 1;
        }
        cout << ans << "\n";
    }else{
        string x;
        cin >> x;
        cout << x.size() << "\n";
        for(int i=0;i<x.size();i++){
            int num = x[i] - 'a' + 1;
            cout << num << " ";
        }
        cout << "\n";
        
    }
}
