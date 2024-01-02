#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

char checkmin(vector<vector<char>> &ans, pair<int,int> c1, pair<int,int> c2){
    vector<bool> forb(26, 0);
    vector<pair<int,int>> v = {c1, c2};
    for(auto c : v){
        for(int i=0;i<4;i++){
            int di = c.first + dx[i];
            int dj = c.second + dy[i];
            if(di < 0 || di >= ans.size()) continue;
            if(dj < 0 || dj >= ans[0].size()) continue;
            if(ans[di][dj] >= 'a' && ans[di][dj] <= 'z'){
                forb[ans[di][dj]-'a'] = true;
            }
        }
    }
    for(char a = 'a'; a <= 'z'; a++){
        if(!forb[a-'a']) return a;
    }
    return '!';
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<char>> ans(n, vector<char>(m));
        int v = (n*m)/2 - k;
        if(n % 2){ //m even
            if(k >= m/2){
                char a = 'a';
                for(int j=0;j<m;j+=2){
                    ans[n-1][j] = a;
                    ans[n-1][j+1] = a;
                    if(a == 'z') a = 'a';
                    else a++;
                }
                k -= m/2;
            }else{
                cout << "NO\n";
                continue;
            }
        }else if(m % 2){
            if(v >= n/2){
                char a = 'a';
                for(int i=0;i<n;i+=2){
                    ans[i][m-1] = a;
                    ans[i+1][m-1] = a;
                    if(a == 'z') a = 'a';
                    else a++;
                }
                v -= n/2;
            }else{
                cout << "NO\n";
                continue;
            }
        }
        if(k % 2) cout << "NO\n";
        else{
            cout << "YES\n";
            for(int i=0;i<n/2;i++){
                for(int j=0;j<m/2;j++){
                    if(k){
                        pair<int,int> p1 = {2*i, 2*j};
                        pair<int,int> p2 = {2*i, 2*j+1};
                        auto c = checkmin(ans, p1, p2);
                        ans[2*i][2*j] = ans[2*i][2*j+1] = c;
                        p1 = {2*i+1, 2*j};
                        p2 = {2*i+1, 2*j+1};
                        c = checkmin(ans, p1, p2);
                        ans[2*i+1][2*j] = ans[2*i+1][2*j+1] = c;
                        k -= 2;
                    }else{  
                        pair<int,int> p1 = {2*i, 2*j};
                        pair<int,int> p2 = {2*i+1, 2*j};
                        auto c = checkmin(ans, p1, p2);
                        ans[2*i][2*j] = ans[2*i+1][2*j] = c;
                        p1 = {2*i, 2*j+1};
                        p2 = {2*i+1, 2*j+1};
                        c = checkmin(ans, p1, p2);
                        ans[2*i][2*j+1] = ans[2*i+1][2*j+1] = c;
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout << ans[i][j];
                }
                cout << "\n";
            }
        }
    }
}
