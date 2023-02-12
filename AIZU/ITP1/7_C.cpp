#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1, vector<int>(m+1));
    for(int i=0;i<n;i++){
        int cs = 0;
        for(int j=0;j<m;j++){
            cin >> v[i][j];
            cs += v[i][j];
        }
        v[i][m] = cs;
    }
    int ts = 0;
    for(int i=0;i<m;i++){
        int cs = 0;
        for(int j=0;j<n;j++){
            cs += v[j][i];
        }
        ts += cs;
        v[n][i] = cs;
    }
    v[n][m] = ts;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << v[i][j];
            if(j!=m) cout << " ";
        }
        cout << "\n";
    }
}

