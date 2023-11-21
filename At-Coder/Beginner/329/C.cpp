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
    int n;
    string s;
    cin >> n >> s;
    vector<int> maxr(26, 0);
    char cur = '\0';
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == cur) cnt++;
        else{
            if(i != 0){
                maxr[cur-'a'] = max(maxr[cur-'a'], cnt);
            }
            cnt = 1;
            cur = s[i];
        }
    }
    maxr[cur-'a'] = max(maxr[cur-'a'], cnt);
    int ans = 0;
    for(int i=0;i<26;i++){
        ans += maxr[i];
    }
    cout << ans << "\n";
}
