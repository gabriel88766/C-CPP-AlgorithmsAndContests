#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
int gr[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if(n == 3){
        cout << "9 5 1\n3 7 8\n6 2 4\n";
    }else if(n % 2 == 0){
        int val = n*n;
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=n;j++){
                gr[i][j] = val;
                val -= 2;
            }
        }
        set<int> al;
        for(int i=1;i<=n*n;i+=2) al.insert(i);
        for(int i=n/2+1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == n/2 + 1){
                    gr[i][j] = n*n - 1 - gr[i-1][j];
                    al.erase(gr[i][j]);
                }else{
                    gr[i][j] = *al.begin();
                    al.erase(al.begin());
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout << gr[i][j] << " ";
            }
            cout << "\n";
        }
    }else{
        //need to find one x + y not prime
        int val = n*n - 1;
        for(int i=1;;i++){
            for(int j=1;j<=n;j++){
                gr[i][j] = val;
                val -= 2;
                if(val == 0) break;
            }
            if(val == 0) break;
        }
        set<int> al;
        for(int i=1;i<=n*n;i+=2) al.insert(i);
        bool flag = false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(gr[i][j]) continue;
                if(gr[i-1][j] % 2 == 0){
                    gr[i][j] = n*n - gr[i-1][j];
                    al.erase(gr[i][j]);
                    if(!flag){
                        flag = true;
                        int r = gr[i][j] % 3;
                        int nr = (3 - r) % 3;
                        for(int k=1;k<=n;k++){
                            if(gr[1][k] % 3 == nr){
                                swap(gr[1][k], gr[i][j-1]);
                                break;
                            }
                        }
                    }
                }else{
                    gr[i][j] = *al.begin();
                    al.erase(al.begin());
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout << gr[i][j] << " ";
            }
            cout << "\n";
        }
    }

}
