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
    string a, b, c;
    cin >> a >> b >> c;
    vector<int> pos(26, 0);
    int x = 0;
    for(auto ch : a){
        pos[ch-'a'] = x++;
    }
    for(auto ch : c){
        if(ch >= '0' && ch <= '9'){
            cout << ch;
            continue;
        }
        char base;
        if(ch >= 'A' && ch <= 'Z') base = 'A';
        else base = 'a';
        int off = ch - base;
        int ro = pos[off];
        int off2 = b[ro] - 'a';
        base += off2;
        cout << base;
    }
    cout << "\n";
}
