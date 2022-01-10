#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

struct edge {

    int end;
    int weight;

    bool operator<(const edge& other) const {
        return weight > other.weight;
    }
};

int V, E, S, u, v, w;
int path[20005];
vector<edge> edges[20005];
priority_queue<edge> nextEdges;

int main(void) {

    scanf("%d %d %d", &V, &E, &S);

    for (int i = 0; i < E; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({ v, w });
    }
    for (int i = 0; i < 20005; ++i)
        path[i] = INF;
    path[S] = 0;

    nextEdges.push({ S, 0 });

    while (!nextEdges.empty()) {
        edge cur = nextEdges.top(); nextEdges.pop();
        int curV = cur.end; int curW = cur.weight;
        if (path[curV] < curW) continue;
        for (int i = 0; i < edges[curV].size(); ++i) {
            int nextV = edges[curV][i].end;
            int nextW = edges[curV][i].weight;
            if (path[nextV] > path[curV] + nextW) {
                path[nextV] = path[curV] + nextW;
                nextEdges.push({ nextV, path[nextV] });
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (path[i] < INF) printf("%d\n", path[i]);
        else printf("INF\n");
    }
    printf("\n");

    return 0;
}
