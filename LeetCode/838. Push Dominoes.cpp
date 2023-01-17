class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<pair<int, char>> domq;
        int n = dominoes.size();

        for(int i = 0; i < n; i++){
            if(dominoes[i] != '.'){
                domq.push({i,dominoes[i]});
            }
        }

        while(!domq.empty()){
            int pos = domq.front().first;
            char domType = domq.front().second;
            domq.pop();

            if(domType == 'L'){
                if(pos > 0 && dominoes[pos-1] == '.'){
                    domq.push({pos-1, 'L'});
                    dominoes[pos-1] = 'L';
                }
            }
            else{
                if(pos+1 < n && dominoes[pos+1] == '.'){
                    if(pos+2 < n && dominoes[pos+2] == 'L'){
                        domq.pop();
                    }
                    else{
                        domq.push({pos+1, 'R'});
                        dominoes[pos+1] = 'R';
                    }
                }
            } 
        }

        return dominoes;
    } 
};