#include <bits/stdc++.h>

using namespace std;

long long int mycount=0;
int cont=0;
char visited[9][9];
int posx=1,posy=1;
string match;
int cont2=0;

void weird_search(){
   if(cont==48){
       cont2++;
        return;
   }

   if(visited[1][7]) return;
   if(posy>1){
        if(!visited[posx][posy-1] && (match[cont] == 'U' || match[cont]=='?')){
            if(visited[posx][posy-2] && !visited[posx+1][posy-1] && !visited[posx-1][posy-1]);
            else{
                cont++;
                visited[posx][--posy] = true;
                weird_search();
                visited[posx][posy++] = false;
                cont--;
            }
        }
   }

   if(posy<7){
        if(!visited[posx][posy+1] && (match[cont] == 'D' || match[cont]=='?')){
             if(visited[posx][posy+2] && !visited[posx+1][posy+1] && !visited[posx-1][posy+1]);
            else{
                 cont++;
                 visited[posx][++posy] = true;
                 weird_search();
                 visited[posx][posy--] = false;
                 cont--;
            }
        }
   }
   if(posx>1){
        if(!visited[posx-1][posy] && (match[cont] == 'L' || match[cont]=='?')){
            if(visited[posx-2][posy] && !visited[posx-1][posy+1] && !visited[posx-1][posy-1]);
            else{
                cont++;
                visited[--posx][posy] = true;
                weird_search();
                visited[posx++][posy] = false;
                cont--;
            }
        }
   }
   if(posx<7){
        if(!visited[posx+1][posy] && (match[cont] == 'R' || match[cont]=='?')){
            if(visited[posx+2][posy] && !visited[posx+1][posy+1] && !visited[posx+1][posy-1]);
            else{
                cont++;
                visited[++posx][posy] = true;
                weird_search();
                visited[posx--][posy] = false;
                cont--;
            }
        }
   }

}


int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
visited[1][1]=true;
cin >> match;
for(int i=0;i<9;i++) visited[0][i] = true, visited[i][0] = true, visited[8][i] = true, visited[i][8] = true;


weird_search();
cout  << cont2;

}


