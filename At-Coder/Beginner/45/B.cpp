#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string sa,sb,sc;
    cin >> sa >> sb >> sc;
    int i = 0, j = 0, k = 0;
    int nxt = 0;
    while(true){
        char c;
        if(nxt == 0 && i == sa.size()) {cout << "A"; return 0;}
        if(nxt == 1 && j == sb.size()) {cout << "B"; return 0;}
        if(nxt == 2 && k == sc.size()) {cout << "C"; return 0;}
        if(nxt == 0) c = sa[i++];
        else if(nxt == 1) c = sb[j++];
        else c = sc[k++];
        if(c == 'a') nxt = 0;
        else if(c == 'b') nxt = 1;
        else nxt = 2;
    }
}
