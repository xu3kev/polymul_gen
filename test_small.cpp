#include<iostream>
#include<immintrin.h>
using namespace std;
void print4(double *x){
    for(int i=0;i<4;++i){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
int main(){

    __m256 a = _mm256_set_pd(1.0, 2.0, 3.0, 4.0);
    __m256 b = _mm256_set_pd(5.0, 6.0, 7.0, 8.0);
    __attribute__ ((aligned (32))) double output[4];
    _mm256_store_pd(output, a);
    print4(output);

    return 0;
}
