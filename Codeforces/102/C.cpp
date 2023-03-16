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
    int k;
    cin >> s >> k;
    vector<int> mp(26, 0);
    for(int i=0;i<s.size();i++){
        mp[s[i]-'a']++;
    }
    vector<pair<int,int>> cp(26);
    for(int i=0;i<26;i++){
        cp[i] = {mp[i], i};
    }
    sort(cp.begin(), cp.end(), greater<pair<int,int>>());
    int minl = s.size()-k;
    if(minl <= 0) cout << "0";
    else{
        int cnt = 0;
        set<char> let;
        for(int i=0;i<cp.size();i++){
            cnt++;
            let.insert('a'+cp[i].second);
            minl -= cp[i].first;
            if(minl <= 0) break;
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(let.count(s[i])) ans += s[i];
        }
        cout << cnt << "\n" << ans;
    }
}
