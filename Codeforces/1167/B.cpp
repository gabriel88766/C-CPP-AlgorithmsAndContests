#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ask(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
vector<int> v = {4, 8, 15, 16, 23, 42};
set<int> s[6];
int cnt[6];
int ans[6];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int s2, s3, s4, s5;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(i == j) continue;
            s[i].insert(v[i] * v[j]);
        }
    }
    ans[1] = ask(1, 2);
    ans[2] = ask(1, 3);
    ans[3] = ask(1, 4);
    ans[4] = ask(1, 5);
    for(int i=0;i<6;i++){
        int cur = 0;
        for(int j=1;j<=4;j++) if(s[i].count(ans[j])) cur++;
        if(cur == 4){
            ans[0] = v[i];
            break; 
        }
    }
    for(int j=1;j<=4;j++) ans[j] /= ans[0];
    for(int i=0;i<6;i++){
        if(v[i] == ans[0]) continue;
        if(v[i] == ans[1]) continue;
        if(v[i] == ans[2]) continue;
        if(v[i] == ans[3]) continue;
        if(v[i] == ans[4]) continue;
        ans[5] = v[i];
    }
    cout << "! ";
    for(int i=0;i<6;i++) cout << ans[i] << " ";
    cout << "\n";
}
