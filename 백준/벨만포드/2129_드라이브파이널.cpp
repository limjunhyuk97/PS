// 생각지도 못한 조건때문에 막힌 벨만-포드 문제
//  - 벨만포드를 구현할 떄, 노드 수 만큼 일단 순회 횟수를 박고 -> 최종에 가서 또 dist 갱신이 벌어진다면 cycle이 있다고 고려하게끔 짠다.
//  - 근데 이 문제는 몇가지 부분에서 기존의 벨만포드 방식과 다른데..
//    - (1) 각 엣지들에 두가지 값이 존재한다. -> 갱신을 고려하기 위해서 '거리'와 '피로도' 라는 두가지의 값을 고려해야 한다.
//    - (2) 세가지 출력값이 존재하는데..
//      - (2-1) 사이클이 존재하면 UNBOUND
//        - 근데, 그래프 아무데서나 사이클 있다고 UNBOUND 출력 아니다.
//        - 목적지까지 도착하는 경로 길이('거리', '피로도' 기준)를 계속해서 줄이는 사이클이 존재하는지를 찾아야 한다.
//        - 근데, '노드 수 만큼만' 전체 반복을 돌리고 목적지까지 도착하는 경로 길이가 안줄었다고 해서 출력하면 틀린다.
//        - 0 <- (-1, 0, 100) -> 1 <- (100, 0, -1) -> 2 <- (-1, 0, 1) -> 2의 형태에서 " 1 -> 0 " 의 경로 찾기 한다 하면..
//          - 2에서 뺑뻉이 겁나 돌리고 1로 올라갔다가 다시 0으로의 dist를 갱신하는 과정이 일어날 수 있는데 이는 '단 3번(노드 수 만큼의 순회)'으로는 발견할 수 없다.
//          - 따라서, 내 풀이에서는 최대 '유의미한' 경로수가 1275(100개노드, fully connected graph edge 수)개, 경로당 최대값 100, -1씩 dist(거리)/fatigue(피로도)를 줄인다면 대략 20005번의 순회를 돌아야 한다 결론이 나오기에, 20005번의 순회를 돌리고 있다.(노드 수 만큼이 아니라)
//      - (2-2) 경로가 없다면 VOID
//        - 위에꺼 다했는데 dist[T], fatigue[T] 값이 INF면 경로 없는거니까
//      - (2-3) 경로가 있다면
//        - dist[T], fatigue[T] 값이 INF 값이 아닌 것이므로 출력한다.
// 너무 어렵다.

#include <iostream>
#include <vector>
#define MAXLEN 105
#define INF 2000000000
#define UNBOUND "UNBOUND"
#define VOID "VOID"
using namespace std;

int N, M, S, T;

// 간선 정보
struct Edge {
    int to;
    int weight;
    int fatigue;
};

// 그래프
vector<Edge> graph[MAXLEN];

// 거리와 피로도 정보
int dist[MAXLEN];
int fatigue[MAXLEN];

// 각 노드에서의 최소 피로도 정보
int min_fatigue[MAXLEN];

// 벨만 포드 알고리즘(시작점, 도착지정,  전체 노드 수)
bool bellmanFord(int s, int t) {
    // 거리 초기화 - 피로도 초기화
    for(int i=0; i<MAXLEN; ++i) {
        dist[i] = INF;
        fatigue[i] = INF;
    }
    // 시작점 거리 - 피로도 0으로 지정
    dist[s] = 0;
    fatigue[s] = 0;
    
    // N(노드 수) 만큼의 순회 시작
    //  - 최대 N-1의 edge를 지나 경로가 생성 될 것. 때문에 N번 갱신을 거듭한다.
    //  - 이때, N번째에도 갱신이 벌어진다면 cycle이 생성 된 것.
    //  - N-1 이하에서 갱신이 더이상 벌어지지 않는다면 s로부터 각 노드들에 대한 최단 경로 고려가 끝난 것.
    bool updated = false;
    int lastF = INF, beforeF = INF, lastD = INF, beforeD = INF;
    for(int i=0; i<20005; ++i) {
        updated = false;
        for(int cur=0; cur<N; ++cur) {
            // 거리와 피로도를 기준으로 다음 것 갱신 여부 확인
            if(fatigue[cur] == INF) continue;
            for(int j=0; j<(int)graph[cur].size(); ++j) {
                // 피로도 -> 이동 가능한 경로를 결정한다.
                if(graph[cur][j].fatigue != min_fatigue[cur]) continue;
                // 갱신 가능 여부 확인
                int next = graph[cur][j].to;
                int nextDist = dist[cur] + graph[cur][j].weight;
                int nextFatigue = fatigue[cur] + graph[cur][j].fatigue;
                // 거리 -> 갱신 여부를 결정한다.
                if(fatigue[next] > nextFatigue || ((fatigue[next] == nextFatigue) && dist[next] > nextDist)) {
                    dist[next] = nextDist;
                    fatigue[next] = nextFatigue;
                    updated = true;
                }
            }
        }
        if(!updated) break;
        if(i == 20005-2) {
            beforeF = fatigue[t];
            beforeD = dist[t];
        }
        if(i == 20005-1) {
            lastF = fatigue[t];
            lastD = dist[t];
        }
    }
    // 마지막까지 갱신이 일어났는데, 목적지로의 dist 값에서의 변경이 일어났다면 빼박 무한 루프
    if(updated && ((beforeF != lastF) || (lastD != beforeD))) return true;
    // 그렇지 않다면 값이 있는 것
    return false;
    
}

int main(void) {
    
    cin >> N >> M >> S >> T;
    
    // 각 노드별 최소 피로도 상태 초기화
    for(int i=0; i<MAXLEN; ++i) {
        min_fatigue[i] = INF;
    }
    
    for(int i=0; i<M; ++i) {
        int u, v, a, c, b;
        cin >> u >> v >> a >> c >> b;
        graph[u].push_back({v, c, a});
        graph[v].push_back({u, c, b});
        min_fatigue[u] = min_fatigue[u] > a ? a : min_fatigue[u];
        min_fatigue[v] = min_fatigue[v] > b ? b : min_fatigue[v];
    }
    
    if(bellmanFord(S, T)) cout << UNBOUND << endl;
    else {
        if(dist[T] == INF) cout << VOID << endl;
        else cout << fatigue[T] << " " << dist[T] << endl;
    }
    
    return 0;
}
