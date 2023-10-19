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
        int n, k;
        string s;
        cin >> n >> k >> s;
        if(k >= 25){
            string str;
            for(int i=0;i<n;i++) str += 'a';
            cout << str << "\n";
        }else{
            map<char, char> mp;
            for(char i = 'a'; i <= 'z'; i++) mp[i] = i;
            for(int i=0;i<n;i++){
                if(k > 0){
                    char mc;
                    for(char j = 'a'; j <= s[i]; j++){
                        if(mp[j] == 'a') mc = j;
                    }
                    int cur = s[i] - mc;
                    if(cur <= k){
                        k -= cur;
                        for(char j=mc;j<=s[i];j++){
                            mp[j] = 'a';
                        }
                    }else{
                        char c = s[i] - k;
                        k = 0;
                        for(char j = c; j <= s[i]; j++){
                            mp[j] = c;
                        }
                    }
                }
                s[i] = mp[s[i]];
            }
            cout << s << "\n";
        }
        
    }
}
