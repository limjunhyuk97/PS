#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdio>
using namespace std;

struct a_order{
    int a;
    int order;
};

vector<int> prime_numbers;

// gcd 구하기
int gcd(int n, int m){
    return (m ? gcd(m, n%m) : n);
}

// euler_phi function
int euler_phi(int n){
    int result = n;
    for(int i=0; i<prime_numbers.size(); ++i){
        if(n < prime_numbers[i]) break;
        if(n % prime_numbers[i] == 0) result = result / prime_numbers[i] * (prime_numbers[i] - 1);
    }
    return result;
}

// 1 - n prime 구하기
void get_prime(int n){
    
    bool number_set[1000];
    fill(number_set, number_set + 1000, true);
    
    for(int i=2; i<1000; ++i){
        if(!number_set[i]) continue;
        prime_numbers.push_back(i);
        int cnt = 2;
        while(i * cnt < 1000){
            number_set[i*cnt] = false;
            cnt += 1;
        }
    }
    
}

int get_order(a_order & pair, int modulo, int euler_phi_val){
    int tmp_a = 1;
    for(int i=1; i<=euler_phi_val; ++i){
        tmp_a *= pair.a;
        if(tmp_a % modulo == 1){
            pair.order = i;
            return 0;
        }
        tmp_a %= modulo;
    }
    return -1;
}

int main(){
    
    int modulo, euler_phi_val;
    vector<a_order> a_order_pair;
    
    cout << "modulo : ";
    cin >> modulo;
    
    for(int i=1; i<modulo; ++i){
        if(gcd(modulo, i) == 1){
            a_order_pair.push_back({i, 0});
        }
    }
    
    get_prime(1000);
    euler_phi_val = euler_phi(modulo);
    
    for(int i=0; i<a_order_pair.size(); ++i){
        if(!get_order(a_order_pair[i], modulo, euler_phi_val)){
            printf("a : %d, order : %d (mod %d)\n", a_order_pair[i].a, a_order_pair[i].order, modulo);
        }
        else{
            printf("error occured. a : %d\n", a_order_pair[i].a);
        }
    }
    
    return 0;
}
