#include <iostream>
#include <utility>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

typedef struct loc{
    int x;
    int y;
}loc;
typedef struct rect{
    loc d;
    loc u;
    bool operator<(const rect &r2) const {
        return (*this).d.x < r2.d.x;
    };
}rect;

typedef pair<int, int> idx_area;

int N, K;
multiset<rect> rects[55];
pair<int,int> area[55];
set<int, less<int> > answer;

void partialize(int lower, int upper){
    int coverdx = (*rects[upper].begin()).d.x, coverdy = (*rects[upper].begin()).d.y, coverux = (*rects[upper].begin()).u.x, coveruy = (*rects[upper].begin()).u.y;
    vector<rect> targets;
    for(auto iter=rects[lower].begin(); iter != rects[lower].end(); ++iter){
        targets.push_back({{(*iter).d.x, (*iter).d.y},{(*iter).u.x, (*iter).u.y}});
    }
    for(int i=0; i<targets.size(); ++i){
        int dx = targets[i].d.x, dy = targets[i].d.y, ux = targets[i].u.x, uy = targets[i].u.y;
        // 1
        if((coverdx<=dx)&&(coverdy > dy && coverdy < uy)){
            if((coverux>dx && coverux<ux) && (coveruy>=uy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,dy},.u={coverux,coverdy}});
                rects[lower].insert({.d={coverux,dy},.u={ux, uy}});
            }
            if((coverux>dx && coverux<ux) && (coveruy<uy && coveruy > dy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,dy},.u={coverux,coverdy}});
                rects[lower].insert({.d={dx,coveruy},.u={coverux, uy}});
                rects[lower].insert({.d={coverux,dy},.u={ux, uy}});
            }
            if((coverux>=ux) && (coveruy>=uy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,dy},.u={ux,coverdy}});
            }
            if((coverux>=ux) && (coveruy<uy && coveruy > dy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,dy},.u={ux,coverdy}});
                rects[lower].insert({.d={dx,coveruy},.u={ux,uy}});
            }
        }
        // 2
        if((coverdx<=dx)&&(coverdy <= dy)){
            if((coverux>dx && coverux<ux) && (coveruy>=uy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={coverux,dy},.u={ux,uy}});
            }
            if((coverux>dx && coverux<ux) && (coveruy<uy && coveruy>dy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,coveruy},.u={coverux,uy}});
                rects[lower].insert({.d={coverux,dy},.u={ux,uy}});
            }
            if((coverux>=ux) && (coveruy<uy && coveruy>dy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,coveruy},.u={ux,uy}});
            }
            if((coverux>=ux) && (coveruy>=uy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
            }
        }
        // 3
        if((coverdx>dx && coverdx<ux)&&(coverdy<=dy)){
            if((coverux<ux) && (coveruy<uy && coveruy>dy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,dy},.u={coverdx,uy}});
                rects[lower].insert({.d={coverdx,coveruy},.u={coverux,uy}});
                rects[lower].insert({.d={coverux,dy},.u={ux,uy}});
            }
            if((coverux<ux) && (coveruy>=uy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,dy},.u={coverdx,uy}});
                rects[lower].insert({.d={coverux,dy},.u={ux,uy}});
            }
            if((coverux>=ux) && (coveruy<uy && coveruy>dy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,dy},.u={coverdx,uy}});
                rects[lower].insert({.d={coverdx,coveruy},.u={ux,uy}});
            }
            if((coverux>=ux) && (coveruy>=uy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,dy},.u={coverdx,uy}});
            }
        }
        // 4
        if((coverdx>dx && coverdx<ux)&&(coverdy>dy && coverdy<uy)){
            if((ux>coverux) && (uy>coveruy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,dy},.u={coverdx,uy}});
                rects[lower].insert({.d={coverdx,dy},.u={coverux,coverdy}});
                rects[lower].insert({.d={coverdx,coveruy},.u={coverux, uy}});
                rects[lower].insert({.d={coverux,dy},.u={ux,uy}});
            }
            if((ux>coverux) && (uy<=coveruy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,dy},.u={coverdx,uy}});
                rects[lower].insert({.d={coverdx,dy},.u={coverux,coverdy}});
                rects[lower].insert({.d={coverux,dy},.u={ux,uy}});
            }
            if((ux<=coverux) && (uy>coveruy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,dy},.u={coverdx,uy}});
                rects[lower].insert({.d={coverdx,dy},.u={ux,coverdy}});
                rects[lower].insert({.d={coverdx,coveruy},.u={ux,uy}});
            }
            if((ux<=coverux) && (uy<=coveruy)){
                rects[lower].erase({{dx,dy},{ux,uy}});
                rects[lower].insert({.d={dx,dy},.u={coverdx,uy}});
                rects[lower].insert({.d={coverdx,dy},.u={ux,coverdy}});
            }
        }
    }
}

int getArea(int idx){
    int sum = 0;
    for(auto iter = rects[idx].begin(); iter != rects[idx].end(); ++iter){
        sum += ((*iter).u.x - (*iter).d.x) * ((*iter).u.y - (*iter).d.y);
    }
    return sum;
}

bool compareArea(const idx_area &n, const idx_area &m){
    if(n.second != m.second) return n.second > m.second;
    else return n.first < m.first;
}

int main(void){
    
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; ++i){
        int dx, dy, ux, uy; scanf("%d %d %d %d", &dx, &dy, &ux, &uy);
        rect rectangle; rectangle.d = {dx, dy}; rectangle.u = {ux, uy};
        rects[i].insert(rectangle);
        for(int j=0; j<i; ++j)
            partialize(j, i);
    }
    
    for(int i=0; i<N; ++i){
        area[i] = {i+1, getArea(i)};
    }
    
    sort(&area[0], &area[N], compareArea);
    
    for(int i=0; i<K; ++i) answer.insert(area[i].first);
    for(auto iter = answer.begin(); iter != answer.end(); ++iter) printf("%d ", (*iter));
    
    printf("\n");
    
    return 0;
}
