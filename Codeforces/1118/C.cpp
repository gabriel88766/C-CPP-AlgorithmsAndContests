#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
void next(int &i, int &j){
    swap(i, j);
    i = n-i-1;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    vector<int> cnt(1001, 0);
    for(int i=0;i<n*n;i++){
        int aux;
        cin >> aux;
        cnt[aux]++;
    }
    int c[4];
    vector<vector<int>> nums(4);
    for(int i=0;i<4;i++) c[i] = 0;
    for(int i=1;i<=1000;i++){
        if(cnt[i] != 0){
            c[cnt[i]%4]++;
            nums[cnt[i]%4].push_back(i);
        }
    }
    bool ok = true;
    if(n % 2){
        if((c[3] == 1 && c[2] < (n-1) && c[1] == 0) || (c[3] == 0 && c[2] <= (n-1) && c[1] == 1));
        else ok = false;
    }else if(c[2] != 0 || c[3] != 0 || c[1] != 0) ok = false;
    if(ok){
        cout << "YES\n";
        vector<vector<int>> ans(n, vector<int>(n, -1));
        int p = 1, aux = -1;
        if(n % 2){
            if(c[3]){
                ans[n/2][n/2] = nums[3][0];
                cnt[nums[3][0]]--;
                nums[2].push_back(nums[3][0]);
            }else{
                ans[n/2][n/2] = nums[1][0];
                cnt[nums[1][0]]--;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j=0;j<n;j++){
                if(ans[i][j] == -1){
                    if(i == n-i-1 && j == n-j-1){
                        //special case;
                        continue;
                    }else if(i == n-i-1){
                        if(nums[2].size()){
                            ans[i][j] = ans[i][n-j-1] = nums[2].back();
                            nums[2].pop_back();
                        }else if(aux != -1){
                            ans[i][j] = ans[i][n-j-1] = aux;
                            aux = -1;
                        }else{
                            while(cnt[p] < 4) p++;
                            ans[i][j] = ans[i][n-j-1] = p;
                            aux = p;
                            cnt[p] -= 4;
                        }
                    }else if(j == n-j-1){
                        if(nums[2].size()){
                            ans[i][j] = ans[n-i-1][j] = nums[2].back();
                            nums[2].pop_back();
                        }else if(aux != -1){
                            ans[i][j] = ans[n-i-1][j] = aux;
                            aux = -1;
                        }else{
                            while(cnt[p] < 4) p++;
                            ans[i][j] = ans[n-i-1][j] = p;
                            aux = p;
                            cnt[p] -= 4;
                        }
                    }else{
                        while(cnt[p] < 4) p++;
                        
                        ans[i][j] = p;
                        ans[i][n-j-1] = p;
                        ans[n-i-1][j] = p;
                        ans[n-i-1][n-j-1] = p;
                        
                        cnt[p] -= 4;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }else cout << "NO\n";
}
