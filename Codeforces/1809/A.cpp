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
        string s;
        cin >> s;
        vector<int> cnt(10,0);
        for(int i=0;i<4;i++) cnt[s[i]-'0']++;
        vector<int> cur;
        for(int i=0;i<10;i++) if(cnt[i]) cur.push_back(cnt[i]);
        
        if(cur.size() == 1) cout << "-1\n";
        else if(cur.size() > 2) cout << "4\n";
        else{
            if(cur[0] == cur[1]) cout << "4\n";
            else cout << "6\n";
        }
    } 
}
