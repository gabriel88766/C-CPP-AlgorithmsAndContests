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
    int p = -1;
    vector<string> vs;
    int lc = 0;
    while(p+1 < s.size()){
        int cnt = 0, q = p;
        while(q+1 < s.size()){
            if(cnt < lc || s[q+1] != ')'){
                if(s[q+1] == ')') cnt++;
                q++;
            }else break;
        }
        //from p+1 to q
        string aux = "";
        lc = 0;
        for(int i=p+1;i<=q;i++){
            aux += s[i];
            if(s[i] == '(') lc++;
        }
        vs.push_back(aux);
        p = q;
    }
    p = 0;
    string ans = "";
    while(ans.size() < s.size()){
        char c = vs[p].back();
        vs[p].pop_back();
        ans += c;
        if(c == '(') p++;
        else p--;
    }
    cout << ans << "\n";
}
