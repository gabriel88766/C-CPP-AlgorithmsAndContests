#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool func(pair<int,int> u, pair<int,int> v){
    if(u.first != v.first) return u.first > v.first;
    else return u.second < v.second;
}

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
        int n = s.size();
        int cost = abs(s.back() - s[0]);
        cout << cost  << " ";
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({s[i], i});
        }
        
        if(s.back() >= s[0]) sort(vp.begin(), vp.end());
        else sort(vp.begin(), vp.end(), func);
        int ind = 0;
        while(vp[ind].second != 0) ind++;
        vector<int> ans;
        ans.push_back(1);
        while(vp[ind].second != n-1){
            ind++;
            ans.push_back(vp[ind].second+1);
        }
        cout << ans.size() << "\n";
        for(auto x: ans) cout << x << " ";
        cout << "\n";
    }
}
