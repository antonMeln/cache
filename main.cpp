# cache
#include <iostream>
#include <chrono>
#include <cmath>
#define LENGTH_ARRAY 262144 // 262144 int * 4 byte = 1mb
#define WARM_COUNT 100000
#define CYCLE_COUNT 1000
int main(int argc, const char * argv[]) {
    int length = 0;
    auto begin = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    
    for(int NumberSize = 0; NumberSize < 5; ++NumberSize){
        
    if(NumberSize == 4) length = LENGTH_ARRAY*12;
    else length =LENGTH_ARRAY*(int)pow(2, NumberSize);
    int* array = new int [length];
    std::cout<<"----------------------/"<<length/LENGTH_ARRAY<<"Mb"<<"/-------------------------"<<'\n'<<'\n';
        
    //warm array
    for (int j = 0; j < WARM_COUNT; ++j) {
    for (size_t i = 0; i < length; ++i) {
        array[i] = 1;
    }
    }
    std::cout<<"Warm Succes"<<"\n";
    
    //direction forward
    begin = std::chrono::steady_clock::now();
    for (int j = 0; j <CYCLE_COUNT; ++j) {
        for (size_t i = 0; i < length; ++i) {
            array[i] = 1;
        }
    }
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout<<"direction forward time "<<elapsed_ms.count()<<" ms"<<'\n';
    
    //direction revers
    begin = std::chrono::steady_clock::now();
    for (int j = 0; j <CYCLE_COUNT; ++j) {
        for (size_t i = length - 1; i > 0; --i) {
            array[i] = 1;
        }
    }
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout<<"direction revers time "<<elapsed_ms.count()<<" ms"<<'\n';
    
    //random
    int t = 0;
    begin = std::chrono::steady_clock::now();
    for (int j = 0; j < CYCLE_COUNT; ++j) {
        for (size_t i = 0; i < length; ++i) {
            t = (int)(rand()%(length));
            array[t] = 1;
        }
    }
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout<<"random time "<<elapsed_ms.count()<<" ms"<<'\n';
        delete [] array;
    }
    return 0;
}
