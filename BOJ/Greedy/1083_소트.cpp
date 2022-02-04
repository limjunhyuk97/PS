// 사전순으로 가장 뒷서는 것 : 왠만하면 수가 내림차순으로 배열되는 것.
// fail1 : 앞에서부터 요소1 < 요소2 관계의 것을 뒤집는 방식으로 구현했으나 로직자체가 틀림.
// success : 앞에서부터, 허용가능 횟수 내에서, 뒤집을 수 있는 가장 큰수를 찾아서, 앞으로 끌고온다.

#include <iostream>
using namespace std;

int N, S;
int arr[55];

void swap(int n, int m){
    int tmp = arr[m];
    for(int i=m-1; i>=n; --i){
        arr[i+1] = arr[i];
    }
    arr[n] = tmp;
}

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) scanf("%d", &arr[i]);
    scanf("%d", &S);
    
    int fix_pos = -1;
    while(S != 0 && fix_pos < N-1){
        int max_num = 0, max_pos = 0, S_tmp = S;
        for(int i=fix_pos+1; i<N && S_tmp>=0; ++i, --S_tmp){
            if(arr[i] > max_num){
                max_num = arr[i];
                max_pos = i;
            }
        }
        if(fix_pos+1 != max_pos) swap(fix_pos+1, max_pos);
        S -= (max_pos - fix_pos - 1 );
        fix_pos += 1;
    }
    
    for(int i=0; i<N; ++i) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
