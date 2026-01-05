#include<bits/stdc++.h>

#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
//matrix vector<vector<int>> matrix(row,vector<int>(col))
typedef long long ll;
using namespace std;

const int N = 2e5+3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

int v[N], ans[N];
bool vis[N];

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int q;
cin >> q;
while(q--){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) vis[i] = false;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i] = true;
            int beg = i;
            int cur = v[i];
            int cont = 1;
            while(cur != beg){
                cont++;
                vis[cur] = true;
                cur = v[cur];
            }
            cur = v[i];
            while(cur != beg){
                ans[cur] = cont;
                cur = v[cur];
            }
            ans[beg] = cont;
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}

}

 