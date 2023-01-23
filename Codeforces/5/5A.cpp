#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s;
    int ans=0, cnt=0;
    while(getline(cin, s)){
        int pos = 0;
        if(s[0] == '+') cnt++;
        else if(s[0] == '-') cnt--;
        else{
            while(s[pos++] != ':');
            ans += (s.size() - pos)*cnt;
        }
    }
    cout << ans;
}
