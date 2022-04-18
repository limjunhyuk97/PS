// 싹다 경우 나누기...?

#include <iostream>
#define MAXCNT 50
using namespace std;

int N;
int colors[6];

int main(void) {
    
    scanf("%d", &N);
    
    int min_color = MAXCNT;
    for(int i=0; i<N; ++i) {
        scanf("%d", &colors[i]);
        if(min_color < colors[i])
            min_color = colors[i];
    }
    
    // thin down
    for(int i=0; i<N; ++i) {
        colors[i] -= min_color;
    }
    
    // feasibility check
    
    
    
    return 0;
}
