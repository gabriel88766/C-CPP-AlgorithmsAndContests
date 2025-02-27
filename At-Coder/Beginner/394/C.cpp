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
    deque<int> dq;
    for(int i=0;i<s.size()-1;i++) dq.push_back(i);
    while(dq.size()){
        auto u = dq.front();
        dq.pop_front();
        if(s[u] == 'W' && s[u+1] == 'A'){
            s[u] = 'A';
            s[u+1] = 'C';
            if(u != 0) dq.push_front(u-1);
        }
    }
    cout << s << "\n";
}
