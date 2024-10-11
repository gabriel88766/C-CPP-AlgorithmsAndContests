#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string query(string s){
    cout << "? " << s << "\n";
    cout.flush();
    string ans;
    cin >> ans;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string ini;
    cin >> ini;
    int n = ini.size();
    string s1 = "", s2 = "", s3 = "";
    for(int i=0;i<n;i++){
        int r1 = i % 26;
        int r2 = (i / 26) % 26;
        int r3 = (i / 676) % 26;
        s1 += (char)('a' + r1);
        s2 += (char)('a' + r2);
        s3 += (char)('a' + r3);
    }
    string ans1 = query(s1);
    string ans2 = query(s2);
    string ans3 = query(s3);
    vector<int> posi(n);
    for(int i=0;i<n;i++){
        int r1 = ans1[i] - 'a';
        int r2 = ans2[i] - 'a';
        int r3 = ans3[i] - 'a';
        posi[i] = r1 + r2*26 + r3 * 676; //string is posi[i] => going to i
    }
    string ans(n, '.');
    for(int i=0;i<n;i++){
        ans[posi[i]] = ini[i];
    }
    cout << "! " << ans << "\n";
    cout.flush();
}
