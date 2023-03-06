#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

deque<char> dq;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    string s;
    cin >> n >> s;
    int rank = 0, minr = 0;
    for(int i=0;i<n;i++){
        if(s[i] == ')') rank--;
        else rank++;
        minr = min(minr, rank);
    }
    for(int i=0;i<abs(minr);i++) s = '(' + s;
    rank = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == ')') rank--;
        else rank++;
    }
    for(int i=0;i<rank;i++) s += ')';
    cout << s;
}
