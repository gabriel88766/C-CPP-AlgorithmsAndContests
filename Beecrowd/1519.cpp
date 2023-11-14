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
    getline(cin, s);
    while(s != "."){
        map<string, int> mp;
        stringstream rs(s);
        string cur;
        while(rs >> cur){
            mp[cur]++;
        }
        vector<int> qnt(26, 0);
        vector<string> best(26);
        for(auto x : mp){
            int sz = x.first.size() - 2;
            sz *= x.second;
            if(sz > qnt[x.first[0]-'a']){
                qnt[x.first[0]-'a'] = sz;
                best[x.first[0]-'a'] = x.first;
            }
        }
        int cnt = 0;
        string ans;
        stringstream rs2(s);
        bool beg = false;
        while(rs2 >> cur){
            if(beg) ans += " ";
            beg = true;
            if(best[cur[0]-'a'] == cur) {ans += cur[0]; ans += '.';}
            else ans += cur;
        }
        cout << ans << "\n";
        for(int i=0;i<26;i++) if(qnt[i] != 0) cnt++;
        cout << cnt << "\n";
        for(int i=0;i<26;i++){
            if(qnt[i] != 0){
                char c = i + 'a';
                cout << c << "." << " = ";
                cout << best[i] << "\n";
            }
        }
        getline(cin, s);
    }
}
