#include<iostream>
#include<immintrin.h>
using namespace std;
void print4(__m256d x){
    __attribute__ ((aligned (32))) double output[4];
    _mm256_store_pd(output, x);
    for(int i=0;i<4;++i){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
#define MUL256(e0,e1,a,b) \
    {__m256d d;\
    __m256d f;\
    __m256d g;\
    __m256d c;\
    e0 = _mm256_setzero_si256();\
    e1 = _mm256_setzero_si256();\
    __m256i mask;\
\
    c = _mm256_permutex_epi64(a, _MM_SHUFFLE(0,0,0,0));\
    d = _mm256_mul_pd(b,c);\
    e0 = _mm256_add_pd(e0,d);\
\
    c = _mm256_permutex_epi64(a, _MM_SHUFFLE(1,1,1,1));\
    g = _mm256_permutex_epi64(b, _MM_SHUFFLE(2,1,0,3));\
    d = _mm256_mul_pd(g,c);\
    mask =_mm256_setr_epi32(0,0,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF);\
    e0 = _mm256_add_pd(e0,((__m256i)d)&mask);\
    e1 = _mm256_add_pd(e1,((__m256i)d)&(~mask));\
\
    c = _mm256_permutex_epi64(a, _MM_SHUFFLE(2,2,2,2));\
    g = _mm256_permutex_epi64(b, _MM_SHUFFLE(1,0,3,2));\
    d = _mm256_mul_pd(g,c);\
    mask =_mm256_setr_epi32(0,0,0,0,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF);\
    e0 = _mm256_add_pd(e0,((__m256i)d)&mask);\
    e1 = _mm256_add_pd(e1,((__m256i)d)&(~mask));\
\
    c = _mm256_permutex_epi64(a, _MM_SHUFFLE(3,3,3,3));\
    g = _mm256_permutex_epi64(b, _MM_SHUFFLE(0,3,2,1));\
    d = _mm256_mul_pd(g,c);\
    mask =_mm256_setr_epi32(0,0,0,0,0,0,0xFFFFFFFF,0xFFFFFFFF);\
    e0 = _mm256_add_pd(e0,((__m256i)d)&mask);\
    e1 = _mm256_add_pd(e1,((__m256i)d)&(~mask));\
    }
int main(){

    __m256d a = _mm256_set_pd(4.0, 3.0, 2.0, 1.0);
    __m256d b = _mm256_set_pd(8.0, 7.0, 6.0, 5.0);
    __m256d e0,e1;
    MUL256(e0,e1,a,b);

    print4(e0);
    print4(e1);


    return 0;
}
