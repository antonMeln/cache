#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <cmath>

#define LENGTH_ARRAY 262144 // 262144 int * 4 byte = 1mb
#define WARM_COUNT 100000
#define CYCLE_COUNT 1000

using namespace std;

int main(int argc, const char * argv[]) {
    int length = 0;
    auto begin = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();
    auto lead_time = chrono::duration_cast<chrono::milliseconds>(end - begin);
    
    for(int NumberSize = 0; NumberSize < 5; ++NumberSize){
        
    if(NumberSize == 4) length = LENGTH_ARRAY*12;
    else length =LENGTH_ARRAY*(int)pow(2, NumberSize);
    int* array = new int [length];
    cout<<"----------------------/"<<length/LENGTH_ARRAY<<"Mb"<<"/-------------------------"<<'\n'<<'\n';
        
    //warm array
    for (int j = 0; j < WARM_COUNT; ++j) {
    for (size_t i = 0; i < length; ++i) {
		array[i] = rand()%100;
    }
    }
    cout<<"Warm Succes"<<"\n";
    
    //forward
    begin = chrono::steady_clock::now();
    for (int j = 0; j <CYCLE_COUNT; ++j) {
        for (size_t i = 0; i < length; ++i) {
            array[i] = rand()%100;
        }
    }
    end = chrono::steady_clock::now();
    lead_time = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout<<"direction forward time "<<lead_time.count()<<" ms"<<'\n';
    
    // revers
    begin = chrono::steady_clock::now();
    for (int j = 0; j <CYCLE_COUNT; ++j) {
        for (size_t i = length - 1; i > 0; --i) {
            array[i] = rand()%100;
        }
    }
    end = chrono::steady_clock::now();
    lead_time = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout<<"direction revers time "<<lead_time.count()<<" ms"<<'\n';
    
    //random
    int t = 0;
    begin = chrono::steady_clock::now();
    for (int j = 0; j < CYCLE_COUNT; ++j) {
        for (size_t i = 0; i < length; ++i) {
            t = (int)(rand()%(length));
            array[t] = 1;
        }
    }
    end = chrono::steady_clock::now();
    lead_time = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout<<"random time "<<lead_time.count()<<" ms"<<'\n';
        delete [] array;
    }
    return 0;
}
