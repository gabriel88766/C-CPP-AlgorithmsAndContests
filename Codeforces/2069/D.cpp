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
        int mi = -1;
        int n = s.size();
        for(int i=0;i<n/2;i++){
            if(s[i] != s[n-i-1]){
                mi = i;
                break;
            }
        }
        if(mi == -1) cout << "0\n";
        else{
            s = s.substr(mi, n-2*mi);
            int ml = s.size();
            int ln = 0;
            for(int i=0;i<s.size()/2;i++){
                if(s[i] != s[s.size() - 1 - i]) ln = i;
            }
            vector<int> c1(26), c2(26);
            for(int i=0;i<=ln;i++){
                c1[s[i]-'a']++;
                c2[s[s.size() - 1 - i] - 'a']++;
            }
            if(c1 == c2) ml = ln + 1;
            else{
                auto solve = [&](){
                    vector<int> c1(26, 0), c2(26, 0);
                    for(auto &c : s){
                        c1[c-'a']++;
                    }
                    int cx = 0;
                    for(auto &c : s){
                        cx++;
                        c1[c-'a']--;
                        c2[c-'a']++;
                        bool ok = true;
                        for(int j=0;j<26;j++){
                            if(c1[j] > c2[j]) ok = false;
                        }
                        if(ok){
                            ml = min(ml, cx);
                            break;
                        }
                    }
                };
                solve();
                reverse(s.begin(), s.end());
                solve();
            }
            cout << ml << "\n";
        }
    }
}
