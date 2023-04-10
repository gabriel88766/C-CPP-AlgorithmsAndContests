#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int mp[26][2];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    for(int i=1;i<=8;i++){
        if(s[i-1] == 'K') mp['K'-'A'][0] = i;
        else if(s[i-1] == 'R'){
            if(mp['R'-'A'][0]) mp['R'-'A'][1] = i;
            else mp['R'-'A'][0] = i;
        }else if(s[i-1] == 'B'){
            if(mp['B'-'A'][0]) mp['B'-'A'][1] = i;
            else mp['B'-'A'][0] = i;
        }
    }
    bool ok = true;
    if((mp['B'-'A'][1]-mp['B'-'A'][0]) % 2 == 0) ok = false;
    if(mp['K'-'A'][0] < mp['R'-'A'][0] || mp['K'-'A'][0] > mp['R'-'A'][1]) ok = false;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
