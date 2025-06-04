#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool us[52];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    bool ok = true;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        int pos = 0;
        if(s[0] == 'H');
        else if(s[0] == 'D') pos = 13;
        else if(s[0] == 'C') pos = 26;
        else if(s[0] == 'S') pos = 39;
        else{
            ok = false;
            continue;
        }
        if(s[1] == 'A');
        else if(s[1] >= '2' && s[1] <= '9') pos += (s[1] - '1');
        else if(s[1] == 'T') pos += 9;
        else if(s[1] == 'J') pos += 10;
        else if(s[1] == 'Q') pos += 11;
        else if(s[1] == 'K') pos += 12;
        else{
            ok = false;
            continue;
        }
        if(us[pos]){
            ok = false;
            continue;
        }else us[pos] = true;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
