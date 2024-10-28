#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+5; 
int sz[2*N];
int len[2][N];
void manacher_odd(string s){
    int n = s.size();
    for(int i=1;i<=n;i++) sz[i] = len[0][i] = len[1][i] = 0;
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
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        bool isp = true;
        for(int i=0;i<n/2;i++){
            if(s[i] != s[n-i-1]) isp = false;
        }
        if(isp){
            manacher(s);
            /*for(int i=1;i<=n;i++) cout << len[0][i] << " ";
            cout << "\n";
            for(int i=1;i<=n;i++) cout << len[1][i] << " ";
            cout << "\n";*/
            int ind = -1;
            for(int i=1;i<n-1;i++){
                //no palins : 0,i and i+1, n
                int sz = i + 1;
                int mid = i/2 + 1;
                if(len[sz%2][mid] == (sz+1)/2) continue;
                sz = n - i - 1;
                mid = i + (sz-1)/2 + 2;
                if(len[sz%2][mid] == (sz+1)/2) continue;
                
                ind = i+1;
                break;
            }
            if(ind == -1) cout << "NO\n";
            else cout << "YES\n2\n" << s.substr(0, ind) << " " << s.substr(ind, n - ind) << "\n";
        }else cout << "YES\n1\n" << s << "\n";
    }
}
