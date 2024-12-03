#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 5e5+3;
int node = 0;
int val[N], p[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //PERSISTENT ARRAY
    val[0] = -1;
    int cur = 0;
    int q;
    cin >> q;
    map<int, int> mp;
    for(int i=0;i<q;i++){
        string s;
        cin >> s;
        if(s == "ADD"){
            int x;
            cin >> x;
            val[++node] = x;
            p[node] = cur;
            cur = node;
        }else if(s == "DELETE"){
            cur = p[cur];
        }else if(s == "SAVE"){
            int x;
            cin >> x;
            mp[x] = cur;
        }else if(s == "LOAD"){
            int x;
            cin >> x;
            if(mp.count(x)) cur = mp[x];
            else cur = 0;
        }else assert("false");
        cout << val[cur] << " ";
    }
    cout << "\n";
}
 