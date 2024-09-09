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
    vector<int> ch1, ch2;
    string s, t;
    cin >> s >> t;
    for(int i=0;i<s.size();i++){
        if(s[i] != t[i]){
            if(s[i] < t[i]) ch2.push_back(i); //increase lexi order
            else ch1.push_back(i); //decrease lexi order
        }
    }
    reverse(ch2.begin(), ch2.end());
    cout << ch1.size() + ch2.size() << "\n";
    string cur = s;
    for(int i=0;i<ch1.size();i++){
        cur[ch1[i]] = t[ch1[i]];
        cout << cur << "\n";
    }
    for(int i=0;i<ch2.size();i++){
        cur[ch2[i]] = t[ch2[i]];
        cout << cur << "\n";
    }
}
