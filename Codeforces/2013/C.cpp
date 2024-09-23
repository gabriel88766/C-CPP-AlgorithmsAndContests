#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ask(string s){
    cout << "? " << s << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string ans = "";
        if(ask("0")) ans += "0";
        else ans += "1";
        while(ans.size() != n){
            if(ask(ans + "0")) ans += "0";
            else if(ask(ans + "1")) ans += "1";
            else break;
        }
        //now ans has size k < n and I made 2*k+1 queries, or ans has size n and I made 2*n-1 queries
        while(ans.size() != n){
            if(ask("0" + ans)) ans = "0" + ans;
            else ans = "1" + ans;
        }
        cout << "! " << ans << "\n";
        cout.flush();
    }
}
