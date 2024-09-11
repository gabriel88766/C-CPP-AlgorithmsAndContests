#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+2;
int ps[N][26];
int cnt[26];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++) ps[i][j] = ps[i-1][j];
        ps[i][s[i]-'a']++;
    }
    int m;
    cin >> m;
    for(int i=1;i<=m;i++){
        string cur;
        cin >> cur;
        for(int j=0;j<26;j++) cnt[j] = 0;
        for(int j=0;j<cur.size();j++) cnt[cur[j]-'a']++;
        int lo = 1, hi = n;
        while(lo != hi){
            bool ok = true;
            int mid = lo + (hi - lo)/2;
            for(int j=0;j<26;j++){
                if(cnt[j] > ps[mid][j]) ok = false;
            }
            if(ok) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}
