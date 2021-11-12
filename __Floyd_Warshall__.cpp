#include <iostream>
#define INF 1e18
using namespace std;

typedef long long int ll;
ll w, path[102][102];
int N, M, u, v;

void Floyd_Warshall(int vertex) {

   for (int k = 1; k <= vertex; ++k) {
      for (int i = 1; i <= vertex; ++i) {
         for (int j = 1; j <= vertex; ++j) {
            if (path[i][j] > path[i][k] + path[k][j])
               path[i][j] = path[i][k] + path[k][j];
         }
      }
   }

}
