#include <bits/stdc++.h>

using namespace std;

int main(){ 
    int n, m;
    cin >> n >> m;
    vector<vector<vector<bool>>> v(n, vector<vector<bool>> (m, vector<bool>(4, false)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                v[i][j][k] = i+j+k;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                cout << v[i][j][k] << ",";
            }
            cout << " ";
        }
        cout << "\n";
    }
}