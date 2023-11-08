#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     int inst = 0;
     while(true){
         int m;
         cin >> m;
         if(m == 0) break;
         inst++;
         cout << "Instancia " << inst << "\n";
         string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
         for(int i = 0; i < m; i++){
            int p;
            cin >> p;
            p--;
            cout << s[p];
            if(p != 0) s = s[p] + s.substr(0, p) + s.substr(p+1, 25-p);
            else s = s[p] + s.substr(1,25);
         }
         cout << "\n\n";
         
     }
 
    return 0;
}