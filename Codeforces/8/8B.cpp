#include <bits/stdc++.h>
using namespace std;
 
bool visited[210][210];
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    int posx = 105, posy = 105;
    visited[105][105] = true;
    bool ok = true;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'U') posy++;
        if(s[i] == 'R') posx++;
        if(s[i] == 'L') posx--;
        if(s[i] == 'D') posy--;
        int cont = 0;
        if(visited[posx][posy]) cont++;
        if(visited[posx+1][posy]) cont++;
        if(visited[posx][posy-1]) cont++;
        if(visited[posx][posy+1]) cont++;
        if(visited[posx-1][posy]) cont++;
        if(cont > 1) ok = false;
        visited[posx][posy] = true;
    }
    if(ok) cout << "OK";
    else cout << "BUG";
    return 0;
}