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
    int n, m;
    cin >> n >> m;
    vector<int> score(n, 0);
    vector<pair<int,int>> p(m);
    vector<string> s(n);
    for(int i=0;i<m;i++){
        cin >> p[i].first;
        p[i].second = i;
    }
    int maxv=0, idmax;
    for(int i=0;i<n;i++){
        cin >> s[i];
        for(int j=0;j<m;j++){
            if(s[i][j] == 'o') score[i] += p[j].first;
        }
        score[i] += i+1;
        if(score[i] > maxv){
            maxv = score[i];
            idmax = i;
        }
    }
    vector<int> ans(n, 0);
    sort(p.begin(), p.end(), greater<pair<int,int>>());
    for(int i=0;i<n;i++){
        if(idmax == i) continue;
        int cur = 0;
        int cursc = score[i];
        for(int j=0;j<m;j++){
            if(s[i][p[j].second] == 'x'){
                cursc += p[j].first;
                cur++;
                if(cursc > maxv) break;
            }
        }
        ans[i] = cur;
    }
    for(int i=0;i<n;i++) cout << ans[i] << "\n";
}
