// 단순한데 헷갈리네...!

// Greedy
// - 정렬 잘하기
// - 어떤 기준으로 요소들을 탐욕스럽게 고를지!

// Sol
// - 내가 처음에 했던 생각 : 강의실을 최대한 붙이려면 현재 고려하는 것 끝나는 시간과 가장 가까운 다음 시작강의가 무엇?
// - 발전된 생각 : "다음 강의 시작시간을 기준"으로 잡기 위해 / 정렬한 뒤에 / "queue에서 하나씩 꺼내면서 확인"한다.

#include <iostream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> itinerary;

struct compare {
    bool operator()(const itinerary & it1, const itinerary & it2){
        if(it1.first != it2.first) return it1.first > it2.first;
        else return it1.second > it2.second;
    }
};

int N, room;
priority_queue<itinerary, vector<itinerary>, compare> IPQ;

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        int s, e, n;
        scanf("%d %d %d", &n, &s, &e);
        IPQ.push(make_pair(s, e));
    }
    
    itinerary cur = IPQ.top(); IPQ.pop();
    room += 1;
    priority_queue<int, vector<int>, greater<int> > EPQ; EPQ.push(cur.second);
    
    while(!IPQ.empty()) {
        cur = IPQ.top(); IPQ.pop();
        
        // 겹쳐진 경우
        if(cur.first < EPQ.top()) {
            room += 1;
            EPQ.push(cur.second);
        }
        // 뒤에다 붙일 수 있는 경우
        else {
            EPQ.pop();
            EPQ.push(cur.second);
        }
    }
    
    printf("%d\n", room);
    
    return 0;
}
