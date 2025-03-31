#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
char gr[N][N];
int tr[N], tc[N];
int cr[N][26], cc[N][26];
bool vr[N], vc[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
            int lt = gr[i][j] - 'a';
            cr[i][lt]++, cc[j][lt]++;
            tr[i]++, tc[j]++;
        }
    }
    queue<int> rc, rr;
    for(int i=1;i<=h;i++){
        for(int j=0;j<26;j++){
            if(cr[i][j] == tr[i]){
                rr.push(i);
                vr[i] = true;
            }
        }
    }
    for(int j=1;j<=w;j++){
        for(int x=0;x<26;x++){
            if(cc[j][x] == tc[j]){
                rc.push(j);
                vc[j] = true;
            }
        }
    }
    while(rr.size() || rc.size()){
        if(rr.size()){
            int i = rr.front();
            rr.pop();
            for(int j=1;j<=w;j++){
                if(gr[i][j]){
                    cc[j][gr[i][j]-'a']--;
                    cr[i][gr[i][j]-'a']--;
                    tc[j]--;
                    tr[i]--;
                    for(int k=0;k<26;k++){
                        if(cc[j][k] == tc[j] && tc[j] > 1 && vc[j] == false){
                            vc[j] = true;
                            rc.push(j);
                        }
                    }
                    gr[i][j] = 0;
                }
            }
        }else{
            int j = rc.front();
            rc.pop();
            for(int i=1;i<=h;i++){
                if(gr[i][j]){
                    cc[j][gr[i][j]-'a']--;
                    cr[i][gr[i][j]-'a']--;
                    tc[j]--;
                    tr[i]--;
                    for(int k=0;k<26;k++){
                        if(cr[i][k] == tr[i] && tr[i] > 1 && vr[i] == false){
                            vr[i] = true;
                            rr.push(i);
                        }
                    }
                    gr[i][j] = 0;
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=h;i++) ans += tr[i];
    cout << ans << "\n";
}
