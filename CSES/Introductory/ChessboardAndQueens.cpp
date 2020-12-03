#include <bits/stdc++.h>

using namespace std;

char matrix[8][8]; //bool

int cont=0;

void weird_search(vector<int> row,vector<int> col){
    int len = row.size();
    //cout << len << endl;
    if(len==8){
        cont++;
        return;
    }
    int pos[8];
    for(int i=0;i<8;i++) pos[i]=1;
    for(int i=0;i<len;i++){
        pos[row[i]] = 0;
        if((row[i]+len-i) <8 ){
            pos[row[i]+len-i]=0;
        }
        if((row[i]-len+i) >=0 ){
            pos[row[i]-len+i]=0;
        }
    }
    for(int i=0;i<8;i++){
        if(pos[i]){
            if(matrix[i][len]=='.'){
                col.push_back(len);
                row.push_back(i);
                weird_search(row,col);
                col.pop_back();
                row.pop_back();
            }
        }
    }

}


int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
vector<int> empty1,empty2;
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        cin >> matrix[i][j];
    }
}
weird_search(empty1,empty2);
cout << cont;
}

