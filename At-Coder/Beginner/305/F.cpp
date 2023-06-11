#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 105;
bool vis[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    stack<int> last;
    int cur = 1;
    vis[1] = true;
    while(cur != n){
        if(cur == 1) last.push(cur);
        int qt;
        cin >> qt;
        vector<int> v(qt);
        for(int i=0;i<qt;i++) cin >> v[i];
        int next = -1;
        for(int i=0;i<qt;i++){
            if(!vis[v[i]]){
                next = v[i];
                break;
            }
        }
        if(next == -1){
            last.pop();
            next = last.top();
        }else{
            last.push(next);
        }
        cur = next;
        cout << cur << "\n";
        cout.flush();
        vis[cur] = true;
    }
    char c;
    cin >> c;

}
