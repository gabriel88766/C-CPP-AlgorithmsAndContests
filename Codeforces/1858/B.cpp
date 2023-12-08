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
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> s(m+2);
        s[0] = 1;
        s[m+1] = n+1;
        for(int i=1;i<=m;i++) cin >> s[i];
        bool fb1 = false;
        int ansn = 1;
        if(s[1] == 1){
            ansn--;
            fb1 = true;
        }
        for(int i=1;i<=m;i++){
            ansn += 1 + (s[i]-s[i-1]-1)/d;
        }
        ansn += (n - s[m])/d;
        vector<int> v;
        for(int i=1;i<=m;i++){
            if(i == 1 && fb1) v.push_back((s[i+1] - s[i-1] - 1)/d - (s[i+1] - s[i] - 1)/d - (s[i] - s[i-1] - 1)/d);
            else v.push_back((s[i+1] - s[i-1] - 1)/d - (s[i+1] - s[i] - 1)/d - (s[i] - s[i-1] - 1)/d - 1);
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        for(int i=0;i<v.size();i++) if(v[0] == v[i]) cnt++;
        cout << ansn + v[0] << " " << cnt << "\n";
    }
}
