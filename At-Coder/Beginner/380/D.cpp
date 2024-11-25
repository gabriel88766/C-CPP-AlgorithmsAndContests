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
    int q;
    cin >> q;
    int n = s.size();
    for(int i=0;i<q;i++){
        ll k;
        cin >> k;
        --k;
        char let = s[k % n];
        int qt = __builtin_popcountll(k / n) % 2;
        if(qt == 0) cout << let << " ";
        else{
            if(let >= 'a' && let <= 'z'){
                let -= 'a';
                let += 'A';
            }else{
                let -= 'A';
                let += 'a';
            }
            cout << let << " ";
        }
    }
    cout << "\n";
}
