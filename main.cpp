#include <iostream>
#include <derive_cal.hpp>

#include <time.h>
#include <stdint.h>
#include <stdio.h>

#ifdef CRTP
template<typename T>
void do_cal(base_cal<T> &base_obj, int & _val){
    base_obj.do_cal(_val);
    return;
}
#endif

int main(int argc, char** argv)
{
    struct timespec begin,end;
    long long unsigned dura;
    int test_val = 0;
    const int rounds = 1000;
    int i = 0;

#ifdef CRTP
    derive_cal test_obj;
#else
    //dynamic polymorphism
    //base pointer which is actually pointed to derive object
    base_cal * test_obj = new derive_cal();
#endif

    //timer start
    clock_gettime(CLOCK_REALTIME, &begin);

//do test
#ifdef CRTP
    for( i = rounds -1; i >= 0; --i){
        do_cal(test_obj, test_val);
    }
#else
    for( i = rounds -1; i >= 0; --i){
        test_obj->do_cal(test_val);
    }
#endif

    //timer stop
    clock_gettime(CLOCK_REALTIME, &end);
    
    //calculate time elapsed
    dura = ((int64_t)end.tv_sec*1000000000 + end.tv_nsec) - 
        ((int64_t)begin.tv_sec*1000000000 + begin.tv_nsec);//ns

#ifdef CRTP
    printf("CRTP TEST:\n");
#else
    printf("NORMAL DYNAMIC POLYMORPHISM TEST:\n");
#endif

    printf("Res = %d\n", test_val);
    printf("Time elapsed : %llu ns\n", dura);



    return 0;
}