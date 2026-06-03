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
        int n = s.size();
        vector<vector<int>> vx(26);
        for(int i=n-1;i>=0;i--){
            vx[s[i]-'a'].push_back(i);
        }
        vector<int> vl, vr;
        for(int i=0;i<n;i++){
            int nm = INF_INT, im = -1;
            for(int j=0;j<26;j++){
                if(j != s[i]-'a' && vx[j].size() && vx[j].back() < nm){
                    nm = vx[j].back();
                    im = j;
                }
            }
            if(im == -1) vl.push_back(i);
            else if(s[i]-'a' < im) vr.push_back(i);
            else vl.push_back(i);
            vx[s[i]-'a'].pop_back();
        }
        vector<int> ord;
        for(auto x : vl) ord.push_back(x);
        reverse(vr.begin(), vr.end());
        for(auto x : vr) ord.push_back(x);
        int ans = ord[(n-1)/2];
        string sans;
        for(int j=0;j<n;j++){
            if(ans != j) sans += s[j];
        }
        cout << sans << "\n";
    }
}
