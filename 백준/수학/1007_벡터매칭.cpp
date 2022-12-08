// (1) 20개의 점 중 2개씩 일일이 선택해서 10개의 벡터를 만드는 방식 -> 19 * 17 * 15 * 13 * ... * 3 * 1 = 654,729,075 의 연산을 수행해야 함. 말이 안됨. 시간이 개미친놈마냥 터짐.
/*

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXLEN 25
#define INF 2000000000
using namespace std;

typedef pair<int, int> Cord;
typedef pair<Cord, Cord> Vector;

int T, N;
bool visited[MAXLEN];
double answer;
vector<Vector> combinations;

void init_visited() {
    fill(&visited[0], &visited[MAXLEN], false);
}

void make_direction_combination(int cnt, int dx, int dy) {
    if(cnt == N/2) {
        if(answer > sqrt((double)dx*dx + (double)dy*dy)) {
            answer = sqrt((double)dx*dx + (double)dy*dy);
        }
        return;
    }
    
    make_direction_combination(cnt+1, dx+(combinations[cnt].second.first - combinations[cnt].first.first), dy+(combinations[cnt].second.second - combinations[cnt].first.second));
    
    make_direction_combination(cnt+1, dx-(combinations[cnt].second.first - combinations[cnt].first.first), dy-(combinations[cnt].second.second - combinations[cnt].first.second));
}

void make_vector_combination(const vector<Cord> cords) {
    if(combinations.size() == N/2) {
        return;
    }
    
    int start = 0;
    for(int i=0; i<N; ++i) {
        if(!visited[i]) {
            start = i;
            visited[start] = true;
            break;
        }
    }
    
    for(int i=0; i<N; ++i) {
        if(visited[i]) continue;
        visited[i] = true;
        combinations.push_back({{cords[start].first, cords[start].second}, {cords[i].first, cords[i].second}});
        make_vector_combination(cords);
        combinations.pop_back();
        visited[i] = false;
    }
    
    visited[start] = false;
    
    return;
}

int main(void) {
    
    vector<Cord> cords;
    scanf("%d", &T);
    
    while(T--) {
        scanf("%d", &N);
        
        cords.clear();
        answer = INF;
        
        for(int i=0; i<N; ++i) {
            int n, m; scanf("%d %d", &n, &m);
            cords.push_back({n, m});
        }
        make_vector_combination(cords);
        printf("%f\n", answer);
    }
    
    return 0;
}
*/

// (2) 벡터 합 구하는 다른 방식 : AB + CD = (D+B) - (A+C)
// 이를 활용하여 끝점, 시작점 덩어리들만 구하면 20C10으로 경우의 수를 줄일 수 있다.

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXLEN 25
#define INF 2000000000
using namespace std;

typedef pair<int, int> Cord;
typedef pair<Cord, Cord> Vector;

int T, N;
bool visited[MAXLEN];
double answer;
vector<Cord> cords;

void make_combination(int cnt, int idx) {
    if(cnt == N/2) {
        int endDx = 0, endDy = 0, startDx = 0, startDy = 0;
        for(int i=0; i<N; ++i) {
            if(visited[i]) {
                endDx += cords[i].first;
                endDy += cords[i].second;
            } else {
                startDx += cords[i].first;
                startDy += cords[i].second;
            }
        }
        
        answer = min(answer, sqrt(pow( (double)startDx - endDx, (double)2 ) + pow((double)startDy - endDy, (double)2) ));
        
        return;
    }
    
    for(int i=idx; i<N; ++i) {
        if(visited[i]) continue;
        visited[i] = true;
        make_combination(cnt+1, i+1);
        visited[i] = false;
    }
    
    return;
}

int main(void) {
    scanf("%d", &T);
    
    while(T--) {
        scanf("%d", &N);
        
        cords.clear();
        answer = INF;
        
        for(int i=0; i<N; ++i) {
            int n, m; scanf("%d %d", &n, &m);
            cords.push_back({n, m});
        }
        
        make_combination(0, 0);
        
        printf("%f\n", answer);
    }
    
    return 0;
}
