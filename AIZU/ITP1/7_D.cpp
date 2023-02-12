#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, l;
    cin >> n >> m >> l;
    vector<vector<int>> u(n, vector<int>(m)), v(m, vector<int> (l));
    vector<vector<long long int>> ans(n, vector<long long int>(l, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> u[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<l;j++){
            cin >> v[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<l;j++){
            for(int k=0;k<m;k++){
                ans[i][j] += u[i][k] * v[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<l;j++){
            cout << ans[i][j];
            if(j != (l-1)) cout << " ";
        }
        cout << "\n";
    }
}

