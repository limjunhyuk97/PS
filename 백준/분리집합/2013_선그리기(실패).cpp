#include <iostream>
#include <set>
#include <algorithm>
#define MAXLEN 10005
using namespace std;

typedef pair<double, double> coord;
typedef pair<coord, coord> line;

int N;
int parent[MAXLEN];
line lines[MAXLEN];

void set_parent(int n) {
    for(int i=0; i<n; ++i) {
        parent[i] = i;
    }
}

int find_parent(int n) {
    if(parent[n] != n) {
        parent[n] = find_parent(parent[n]);
    }
    return parent[n];
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool isLine(line A, line B) {
    coord A1 = A.first, A2 = A.second;
    if(A2.first < A1.first || A2.second < A1.second) swap(A1, A2);
        
    coord B1 = B.first, B2 = B.second;
    if(B2.first < B1.first || B2.second < B1.second) swap(B1, B2);
    
    // 모두 일치
    if(A1 == B1 && A2 == B2) return true;
    // 하나만 일치
    if(A2 == B1 || A1 == B2) {
        // 수평선
        if(A1.second == A2.second || B1.second == B2.second) {
            if(A1.second == A2.second && B1.second == B2.second) return true;
            else return false;
        }
        // 수직선
        else if(A1.first == A2.first || B1.first == B2.first) {
            if(A1.first == A2.first && B1.first == B2.first) return true;
            else return false;
        }
        // 선분
        else {
            if((A2.second-A1.second)/(A2.first-A1.first) == (B2.second-B1.second)/(B2.first-B1.first)) return true;
            else return false;
        }
    }
    // 하나도 안일치
    else {
        // 수평선
        if(A1.second == A2.second || B1.second == B2.second) {
            if(A1.second == A2.second && B1.second == B2.second) {
                if((A1.first <= B1.first && B1.first <= A2.first) || (B1.first <= A1.first && A1.first <= B2.first)) return true;
                else return false;
            }
            else return false;
        }
        // 수직선
        else if(A1.first == A2.first || B1.first == B2.first) {
            if(A1.first == A2.first && B1.first == B2.first) {
                if((A1.second <= B1.second && B1.second <= A2.second) || (B1.second <= A1.second && A1.second <= B2.second)) return true;
                else return false;
            }
            return false;
        }
        // 선분
        else {
            if((A2.second-A1.second)/(A2.first-A1.first) == (B2.second-B1.second)/(B2.first-B1.first)) {
                if(((A1.first <= B1.first && B1.first <= A2.first) && (A1.second <= B1.second && B1.second <= A2.second)) || ((B1.first <= A1.first && A1.first <= B2.first) && (B1.second <= A1.second && A1.second <= B2.second))) {
                    return true;
                }
                else return false;
            } else {
                return false;
            }
        }
    }
}

void setLine(line &parent, const line &child) {
    coord &P1 = parent.first, &P2 = parent.second;
    if(P2.first < P1.first || P2.second < P1.second) swap(P1, P2);
    
    coord C1 = child.first, C2 = child.second;
    if(C2.first < C1.first || C2.second < C1.second) swap(C1, C2);
    
    if(C1.first < P1.first || C1.second < P2.second) P1 = C1;
    if(P2.first < C2.first || P2.second < C2.second) P2 = C2;
}

int main(void) {
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        double x1, y1, x2, y2;
        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
        lines[i] = {{x1, y1}, {x2, y2}};
    }
    
    set_parent(N);
    
    for(int i=0; i<N; ++i) {
        set<int> visited;
        for(int j=0; j<i; ++j) {
            if(visited.find(find_parent(j)) != visited.end()) continue;
            
            // j가 i의 부모라면
            if(isLine(lines[i], lines[j])) {
                union_parent(i, j);
                setLine(lines[j], lines[i]);
            }
            
            visited.insert(find_parent(j));
        }
    }
    
    set<int> parents;
    for(int i=0; i<N; ++i) {
        if(parents.find(find_parent(i)) == parents.end() ){
            parents.insert(find_parent(i));
        }
    }
    
    cout << parents.size() << endl;
    
    return 0;
}
