#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[26][51];
int mincnt[26];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string ans;
    int n;
    cin >> n;
    memset(mincnt, 63, sizeof(mincnt));
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++){
            cnt[s[j]-'a'][i]++;
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<n;j++){
            mincnt[i] = min(cnt[i][j], mincnt[i]);
        }
    }
    for(int i=0;i<26;i++)
        for(int j=0;j<mincnt[i];j++) ans += 'a'+i;
    cout << ans << "\n";
}
