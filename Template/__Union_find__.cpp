#include <iostream>
#include <algorithm>
using namespace std;

// union - find 1 //
const int MAX_SIZE = 6;
int par[MAX_SIZE + 1];

// forest 초기화
void make_set() {
   for (int i = 1; i <= MAX_SIZE; ++i)
      par[i] = i;
}

// find 연산 (Collapsing Find의 재귀적 방식 방식)
int Find(int num) {
   if (par[num] == num) return num;
   else return par[num] = Find(par[num]);
}

// path compression (Weighted된 경우는 아니다.)
void Union(int a, int b) {
   if (Find(a) != Find(b)) par[Find(b)] = Find(a);
}


// union - find 2 //
class Sets {
private :
   int* parent;
   int n;

public :
   Sets(int numberOfElements) {
      if (numberOfElements < 2) throw "Must have at least 2 elements.";
      n = numberOfElements;
      parent = new int[n];
      fill(parent, parent + n, -1);
   }

   void SimpleUnion(int i, int j) {
      parent[i] = j;
   }

   int SimpleFind(int i) {
      while (parent[i] >= 0)
         i = parent[i];
      return i;
   }

   // path compression (Weighted된 경우이다.) : parent 배열의 root 인덱스 부분에 set에 포함된 node의 수를 넣는다.
   void WieghtedUnion(int i, int j) {
      
      int iroot = CollapsingFind(i);
      int jroot = CollapsingFind(j);
      int tmp = parent[iroot] + parent[jroot];

      // node의 수가 더 많은 곳에 node의 수가 더 적은 것을 붙인다.
      // iroot set보다 jroot set에 노드의 수가 많다
      if (jroot != iroot) {
         if (parent[iroot] > parent[jroot]) {
            parent[iroot] = jroot;
            parent[jroot] = tmp;
         }
         // jroot보다 iroot에 노드의 수가 많다
         else {
            parent[jroot] = iroot;
            parent[iroot] = tmp;
         }
      }

   }

   // find 연산 (Collapsing Find의 반복적 방식)
   int CollapsingFind(int i) {
      int r = i;
      // root를 찾는 과정
      for (; parent[r] >= 0; r = parent[r]);
      while (i != r) {
         int tmp = par[i];
         par[i] = r;
         i = tmp;
      }
      return r;
   }

   ~Sets() {
      delete[] parent;
   }

};

int main(void) {

   Sets set1(6);

   set1.WieghtedUnion(2, 3);
   set1.WieghtedUnion(4, 5);
   set1.WieghtedUnion(0, 2);

   for (int i = 0; i < 6; ++i)
      cout << set1.SimpleFind(i) << " ";

   return 0;

}
