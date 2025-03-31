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
    int n, r, c, cx = 0, cy = 0;
    string s;
    set<pair<int, int>> st;
    cin >> n >> r >> c;
    cin >> s;
    st.insert({0, 0});
    for(int i=0;i<n;i++){
        if(s[i] == 'N') cx--;
        else if(s[i] == 'S') cx++;
        else if(s[i] == 'W') cy--;
        else cy++;
        st.insert({cx, cy});
        if(st.count(make_pair(cx - r, cy - c))) cout << "1";
        else cout << "0";
    }
    cout << "\n";
}

