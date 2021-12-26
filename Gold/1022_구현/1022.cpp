#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <array>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

int r1, c1, r2, c2;

int num_len(int num){
    int cnt = 0;
    while(num > 0){
        num /= 10;
        cnt++;
    }
    return cnt;
}

int num_absolute(int num){
    return num > 0 ? num : -num;
}

// location : 0 - ul, 1 - ur, 2 - dr , 3 - dl
int end_point(int num, int location){
    switch(location){
        case 0:
            return 4 * num * num + 1;
        case 1:
            return 4 * num * num - 2 * num + 1;
        case 2:
            return 4 * num * num + 4 * num + 1;
        case 3:
            return 4 * num * num + 2 * num + 1;
        default:
            return 0;
    }
}

int point(int i, int j){
    
    if (i == 0 && j == 0) return 1;
    
    int i_val = num_absolute(i);
    int j_val = num_absolute(j);
    
    if (i_val == j_val){
        if(i > 0){
            if(j > 0) return end_point(i_val, 2);
            else return end_point(i_val, 3);
        }
        else{
            if(j > 0) return end_point(i_val, 1);
            else return end_point(i_val, 0);
        }
    }
    else if(i_val > j_val){
        // 절댓값 큰 수가 양수
        if(i > 0) return end_point(i, 2) - (i - j);
        // 절댓값 큰 수가 음수
        else return end_point(i, 0) - (j - i);
    }
    else{
        // 절댓값 큰 수가 양수
        if(j > 0) return end_point(j, 1) - (i + j);
        // 절댓값 큰 수가 음수
        else return end_point(j, 0) + (i - j);
    }
}

int main(void){
    
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    
    // 최대 길이의 숫자 확인
    int end_points[4];
    end_points[0] = point(r1, c1);
    end_points[1] = point(r1, c2);
    end_points[2] = point(r2, c2);
    end_points[3] = point(r2, c1);
    int max_len = num_len(*max_element(end_points, end_points + 4));
    
    // 출력
    for(int i=r1; i<=r2; ++i){
        for(int j=c1; j<=c2; ++j){
            int num = point(i, j);
            int dif = max_len - num_len(num);
            for(int k=0; k<dif; ++k) printf(" ");
            if(j != c1) printf(" ");
            printf("%d", num);
        }
        printf("\n");
    }
    
    return 0;
}
