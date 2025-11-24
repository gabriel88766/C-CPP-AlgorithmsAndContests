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
    string s;
    cin >> s;
    vector<int> cnt(3);
    for(auto c : s){
        int cr = (c - '0') % 3;
        cnt[cr]++;
    }
    if(cnt[0] || (cnt[1] && cnt[2]) || cnt[1] >= 3 || cnt[2] >= 3){
        int x = cnt[1] + 2 * cnt[2];
        x %= 3;
        if(x == 0) cout << "0\n";
        else if(x == 1){
            if(cnt[1]) cout << "1\n";
            else cout << "2\n";
        }else{
            if(cnt[2]) cout << "1\n";
            else cout << "2\n";
        }
    }else cout << "-1\n";
}
