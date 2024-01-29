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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    set<int> ta, tb;
    int fa = INF_INT, lb = -1;
    for(int i=0;i<n;i++){
        if(s[i] != t[i]){
            if(s[i] == 'A') tb.insert(i);
            else ta.insert(i);
        }
        if(t[i] == 'A' && fa == INF_INT) fa = i;
        if(t[i] == 'B') lb = i;
    }
    if(ta.size() == 0 && tb.size() == 0) cout << "0\n";
    else if(ta.size() && *prev(ta.end()) > lb) cout << "-1\n";
    else if(tb.size() && *tb.begin() < fa) cout << "-1\n";
    else{
        int ans = 0;
        while(ta.size() || tb.size()){
            ans++;
            if(ta.size()){
                if(tb.size()){
                    auto it = tb.lower_bound(*ta.begin());
                    ta.erase(ta.begin());
                    if(it != tb.end()) tb.erase(it);
                }else{
                    ta.erase(ta.begin());
                }
            }else{
                tb.erase(tb.begin());
            }
        }
        cout << ans << "\n";
    }
}
