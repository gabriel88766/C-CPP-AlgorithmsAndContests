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
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<int> cur(26);
    for(int i=0;i<26;i++) cur[i] = i;
    for(int i=0;i<q;i++){
        char c, d;
        cin >> c >> d;
        int src = c-'a';
        int dst = d-'a';
        for(int i=0;i<26;i++){
            if(cur[i] == src) cur[i] = dst;
        }
    }
    for(int i=0;i<n;i++){
        char c = 'a' + cur[s[i]-'a'];
        cout << c;
    }
    cout << "\n";
}
