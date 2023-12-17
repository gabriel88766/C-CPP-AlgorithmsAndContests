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
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        vector<vector<int>> oc(26);
        for(int i=0;i<n;i++){
            oc[s[i]-'a'].push_back(i);
        }
        int l = -1;
        vector<int> subs;
        char cur = 25;
        while(cur >= 0){
            auto it = upper_bound(oc[cur].begin(), oc[cur].end(), l);
            if(it != oc[cur].end()){
                l = *it;
                subs.push_back(l);
            }else cur--;
        }
        int ans = 0;
        for(auto x : subs){
            if(s[x] != s[subs[0]]) ans++;
        }
        int p1 = subs.size() - 1, p2 = 0;
        string aux;
        for(int i=0;i<n;i++){
            if(p2 < subs.size() && subs[p2] == i){
                aux += s[subs[p1--]];
                p2++;
            }else{
                aux += s[i];
            }
        }
        string aux2 = aux;
        sort(aux2.begin(), aux2.end());
        if(aux == aux2) cout << ans << "\n";
        else cout << "-1\n";
    }
}
