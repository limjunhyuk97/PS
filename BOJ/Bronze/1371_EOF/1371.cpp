// BOJ에서는 입력을 넣을 때 파일로 주기 때문에 EOF가 붙어있다.
// 파일의 끝은 cin.eof()가 true를 반환하는 것으로 확인할 수 있다.
// getline(cin, string) 함수는 eof를 만나면 false를 반환한다.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> paragraph;
string str;
int alphabet[35];

int main(void){
    
    while(getline(cin, str)){
        paragraph.push_back(str);
    }
    
    for(int i=0; i<paragraph.size(); ++i){
        for(int j=0; j<paragraph[i].size(); ++j){
            if(paragraph[i][j] != ' ')
                alphabet[paragraph[i][j] - 'a']++;
        }
    }
    
    int maxnum = *max_element(alphabet, alphabet + 35);
    for(int i=0; i<35; ++i){
        if(alphabet[i] == maxnum)
            cout << (char)(i + 'a');
    }
    cout << "\n";
    
    return 0;
}
