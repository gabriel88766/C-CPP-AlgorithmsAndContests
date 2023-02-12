#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<int> a(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    for(int i=0;i<m;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        int curv = 0;
        for(int j=0;j<m;j++){
            curv += v[i][j] * a[j];
        }
        cout << curv << "\n";
    }
}

