#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
int n, k;
char gr[N][N];
ll ans[26];
int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
        }
    }
    vector<pair<int, int>> qw;
    ll cur = 0;
    for(int i=n;i>=1;i--){
        qw.clear();
        cur = 0;
        for(int j=n;j>=1;j--){
            if(gr[i][j] == gr[i+1][j]) cnt[j]++;
            else cnt[j] = 1;
            //NOW DO THE MIN QUEUE JOB!
            if(gr[i][j] == gr[i][j+1]){
                ll bg = j, val;
                while(qw.size() && qw.back().first >= cnt[j]){
                    //WHAT TO DO, HELPPPPP!!!
                    bg = qw.back().second;
                    val = qw.back().first;
                    qw.pop_back();
                    cur -= (val - max(cnt[j], (qw.size() ? qw.back().first : 0))) * (bg - j);
                }
                qw.push_back({cnt[j], bg});
                cur += cnt[j];
            }else{
                //remake the queue
                qw.clear();
                cur = 0;
                cur += cnt[j];
                qw.push_back({cnt[j], j});
            }
            ans[gr[i][j]-'A'] += cur;
        }
    }
    for(int j=0;j<k;j++) cout << ans[j] << "\n";
}
