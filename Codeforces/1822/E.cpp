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
        if(n%2) cout << "-1\n";
        else{
            vector<int> cnt1(26, 0), cnt2(26,0);
            for(int i=0;i<n/2;i++){
                if(s[i] == s[n-i-1]){
                    cnt1[s[i]-'a']++;
                }else{
                    cnt2[s[i]-'a']++;
                    cnt2[s[n-i-1]-'a']++;
                }
            }
            vector<int> v;
            for(int i=0;i<26;i++) if(cnt1[i]) v.push_back(cnt1[i]);
            if(v.size() == 0){
                cout << "0\n";
                continue;
            }
            sort(v.begin(), v.end(), greater<int>());
            int S = 0;
            for(int i=1;i<v.size();i++) S += v[i];
            if(S >= v[0]){
                int ans = S + v[0];
                cout << (ans/2 + ans%2) << "\n";
            }else{
                int ans = S;
                int ttl = S + v[0];
                int rl = n/2 - ttl;
                int index;
                for(int i=0;i<26;i++) if(cnt1[i] == v[0]) index = i;
                v[0] -= S;
                if(rl-cnt2[index] >= v[0]) cout << ans + v[0] << "\n";
                else cout << "-1\n";
            }
        }
    }
}
