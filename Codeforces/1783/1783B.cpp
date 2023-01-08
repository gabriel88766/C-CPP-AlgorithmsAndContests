#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    vector<vector<int>> v(52, vector<int> (52,0));
    char visited[52][52];
    while(t--){
        int n;
        cin >> n;
        for(int i=0;i<=(n+1);i++){
            visited[0][i] = true;
            visited[i][0] = true;
            visited[n+1][i] = true;
            visited[i][n+1] = true;
        }
        for(int i=1;i<=n;i++){
            for(int w=1;w<=n;w++){
                visited[i][w] = false;
            }
        }
        int j = 1, k = n*n, curi = 1, curj = 1;
        char direction = 'D';

        for(int i=1;i<= (n*n); i++){
            if(i % 2) v[curi][curj] = j++;
            else v[curi][curj] = k--;
            visited[curi][curj] = true;
            if(i == (n*n)) break;
            if(direction == 'D'){
                if(!visited[curi+1][curj]){
                    curi++;
               }else{
                    curj++;
                    direction = 'R';
                }
            }else if(direction == 'R'){
                if(!visited[curi][curj+1]){
                    curj++;
                }else{
                    curi--;
                    direction = 'U';
                }
            }else if(direction == 'U'){
                if(!visited[curi-1][curj]){
                    curi--;
                }else{
                    curj--;
                    direction = 'L';
                }
            }else{
                if(!visited[curi][curj-1]){
                    curj--;
                }else{
                    curi++;
                    direction = 'D';
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int w=1;w<=n;w++){
                cout << v[i][w] << " ";
            }
            cout <<"\n";
        }
    }
}
