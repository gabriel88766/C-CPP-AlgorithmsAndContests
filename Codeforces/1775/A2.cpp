#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        if(s[1] == 'a') cout << s.substr(0,1) << " " << s.substr(1, 1) << " " << s.substr(2, s.size()-2) << "\n";
        else cout << s.substr(0,1) << " " << s.substr(1, s.size()-2) << " " << s.substr(s.size()-1 , 1) << "\n";
    }
}
 