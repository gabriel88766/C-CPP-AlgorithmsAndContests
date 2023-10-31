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
        int cnt[4];
        for(int i=0;i<4;i++) cnt[i] = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'L') cnt[0]++;
            if(s[i] == 'R') cnt[1]++;
            if(s[i] == 'D') cnt[2]++;
            if(s[i] == 'U') cnt[3]++;
        }
        int mh = min(cnt[0], cnt[1]);
        int mv = min(cnt[2], cnt[3]);
        if(mh && mv){
            int ans =  2*(mh + mv);
            cout << ans << "\n";
            for(int i=0;i<mh;i++) cout << "R";
            for(int i=0;i<mv;i++) cout << "U";
            for(int i=0;i<mh;i++) cout << "L";
            for(int i=0;i<mv;i++) cout << "D";
            cout << "\n";
        }else if(mh){
            cout << "2\n";
            cout << "LR\n";
        }else if(mv){
            cout << "2\n";
            cout << "UD\n";
        }else{
            cout << "0\n";
        }
    }
}
