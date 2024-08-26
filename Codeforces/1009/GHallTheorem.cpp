#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;

int cnt[N], cnt2[N];
string x[N];
int msk[N];
int cm[64], cm2[64];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    int m;
    cin >> s >> m;
    int n = s.size();
    for(int i=1;i<=n;i++) x[i] = "abcdef";
    for(int i=0;i<m;i++){
        int p;
        string xx;
        cin >> p >> xx;
        sort(xx.begin(), xx.end());
        x[p] = xx;
    }
    for(int i=0;i<n;i++) cnt[s[i]-'a']++;
    for(int i=1;i<=n;i++){
        for(auto c : x[i]){
            msk[i] |= (1 << (c-'a'));
        }
        cm[msk[i]]++;
    }
    for(int i=0;i<64;i++){
        for(int j=0;j<64;j++){
            if((i & j) != 0){
                cm2[i] += cm[j];
            }
        }
    }
    bool ok = true;
    for(int i=0;i<64;i++){
        //subset "a, b, c"
        int cur = 0;
        for(int j=0;j<6;j++){
            if(i & (1 << j)) cur += cnt[j];
        }
        if(cur > cm2[i]) ok = false;
    }
    if(ok){
        string ans = "";
        for(int i=1;i<=n;i++){
            for(int m=0;m<64;m++){
                if((m & msk[i]) != 0){
                    cm2[m]--;
                }
            }
            for(int j=0;j<6;j++){
                if(!(msk[i] & (1 << j))) continue;
                bool ok = true;
                cnt[j]--;
                for(int m=0;m<64;m++){
                    //subset "a, b, c"
                    int cur = 0;
                    for(int j=0;j<6;j++){
                        if(m & (1 << j)) cur += cnt[j];
                    }
                    if(cur > cm2[m]) ok = false;
                }
                if(ok){
                    ans += (char)('a' + j);
                    break;
                }else cnt[j]++;
            }
        }
        cout << ans << "\n";
    }else cout << "Impossible\n";
    
}
