#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//len[1][i] the size of odd palindrome
//len[0][i] the size of even palindrome (center in left)
const int N = 500005; 
int sz[2*N];
int len[2][N];
void manacher_odd(string s){
    int n = s.size();
    s = '^' + s + '$';
    int l = 0, r = 1;
    for(int i=1;i<=n; i++){
        if(i >= r){
            while(s[i - sz[i]] == s[i + sz[i]]) sz[i]++;
        }else{
            int p = l + r - i;
            sz[i] = min(sz[p], p - l);
            while(s[i - sz[i]] == s[i + sz[i]]) sz[i]++;
        }
        if(i + sz[i] > r){
            r = i + sz[i];
            l = i - sz[i];
        }
    }
}

void manacher(string s){
    int n = s.size();
    string t;
    for(int i=0;i<n;i++){
        t += '#';
        t += s[i];
    }
    t += '#';
    manacher_odd(t);
    for(int i=1;i<=n;i++){
        len[0][i] = sz[2*i+1]/2;
        len[1][i] = sz[2*i]/2;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    auto x = s;
    reverse(x.begin(), x.end());
    if(x == s) cout << s << "\n";
    else{
        manacher(s);
        for(int i=1;i<=s.size();i++){
            int mss = s.size() - i;
            if(len[1][i] == mss + 1){
                int j = s.size() - 2*mss - 1;
                string x = s.substr(0, j);
                reverse(x.begin(), x.end());
                cout << s <<  x << "\n";
                break;
            }else if(len[0][i] == mss){
                int j = s.size() - 2*mss;
                string x = s.substr(0, j);
                reverse(x.begin(), x.end());
                cout << s << x << "\n";
                break;
            }
        }
    }
}   
