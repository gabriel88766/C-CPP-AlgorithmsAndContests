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
    string s;
    int n;
    cin >> n;
    cin >> s;
    for(int i=1;i<s.size();i++){
        int cnt = 0;
        for(int j=0;j<(s.size()-i); j++){
            if(s[j] != s[j+i]) cnt++;
            else break;
        }
        cout << cnt << "\n";
    }
}
