#include <bits/stdc++.h>
 
using namespace std;
const int N = 1e5+3, INF = 0x3f3f3f3f;
bool isp[26];
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n, m, cont=0;
    char c;
    cin >> n >> m >> c;
    char matrix[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == c){
                if(i>0 && matrix[i-1][j] >= 'A' && matrix[i-1][j] <= 'Z' && matrix[i-1][j] != c) isp[matrix[i-1][j]-'A'] = true;
                if(j>0 && matrix[i][j-1] >= 'A' && matrix[i][j-1] <= 'Z' && matrix[i][j-1] != c) isp[matrix[i][j-1]-'A'] = true;
                if(i<(n-1) && matrix[i+1][j] >= 'A' && matrix[i+1][j] <= 'Z' && matrix[i+1][j] != c) isp[matrix[i+1][j]-'A'] = true;
                if(j<(m-1) && matrix[i][j+1] >= 'A' && matrix[i][j+1] <= 'Z' && matrix[i][j+1] != c) isp[matrix[i][j+1]-'A'] = true;
            }
        }
    }
    for(int i=0;i<26;i++) if(isp[i]) cont++;
    cout << cont;
}