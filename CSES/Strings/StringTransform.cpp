#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[26];
const int N = 1e6+3;
int pos1[N][26];
int pos2[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int fp = 0;
    for(int i=0;i<s.size();i++){
        auto &x = s[i];
        if(x >= 'a' && x <= 'z') {
            pos1[cnt[x-'a']++][x-'a'] = i;
        }else fp = i;
    }
    string lx = "#";
    for(int i=0;i<26;i++){
        int xx = 0;
        while(cnt[i]--) {
            pos2[lx.size()] = xx++;
            lx += 'a' + i;
        }
    }
    
    string ans;
    ans += lx[fp];
    int cp = fp;
    while(true){
        int np;
        np = pos1[pos2[cp]][lx[cp]-'a'];
        if(lx[np] == '#') break;
        else ans += lx[np];
        cp = np;
    }
    cout << ans << "\n";
}
