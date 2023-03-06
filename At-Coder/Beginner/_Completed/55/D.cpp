#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;

bool check(string &ans, string &s){
    int n = s.size();
    for(int i=1;i<(n-1);i++){
        if(!((s[i] == 'o') ^ (ans[i] == 'S'))) ans += ans[i-1];
        else ans += (ans[i-1] == 'S' ? 'W' : 'S');
    }
    if((s[n-1] == 'o') ^ (ans[n-1] == 'S') ^ (ans[n-2] != ans[0])) return false;
    if((s[0] == 'o') ^ (ans[0] == 'S') ^ (ans[n-1] != ans[1])) return false;
    return true;
}

string pos[4] = {"SS", "SW", "WS", "WW"};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<4;i++){
        if(check(pos[i], s)){
            cout << pos[i];
            return 0;
        }
    }
    
    cout << -1;
}
