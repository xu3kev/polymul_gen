from gen import *
from random import randint

n = 64
a = [Var(('a',i)) for i in range(n)]
b = [Var(('b',i)) for i in range(n)]

def def_input(x):
    for v in x:
        print("{} = {}".format(v, randint(0,4)))

def show_var(x):
    print("print({})".format(",".join(str(v) for v in x)))

header = """
#include<x86intrin.h>
#include<immintrin.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
"""

timing_function="""
 inline uint64_t readTSCp() {
     unsigned dummy;
     return __rdtscp(&dummy);
  }
"""

def show_output256(c):
    print("__attribute__ ((aligned (32))) double output[{}];".format(len(c)*4))
    for i,v in enumerate(c):
        print("_mm256_store_pd(output+{}, {});".format(str(4*i),v))
    
    print("""for(int i=0;i<{};++i) 
    printf(" %f",output[i]);
    printf("\\n");
    """.format(len(c)*4))


body="""
int main(){
"""
set_input="""
    __attribute__ ((aligned (32))) double a[{N}];
    __attribute__ ((aligned (32))) double b[{N}];
    for(int i=0;i<{N};++i){{
        a[i] = rand()%10;
        printf(" %f", a[i]);
    }}
    printf("\\n");
    for(int i=0;i<{N};++i){{
        b[i] = rand()%10;
        printf(" %f", b[i]);
    }}
    printf("\\n");

""".format(N=n*4)

c = polymul(a,b,["k","k","k","k","k","k","s"])

print(header)
print(MUL_MACRO)
print(timing_function)
print(body)
print(set_input)
print("__m256d {};".format(",".join(str(v) for v in Var.all_vars)))
#def_input(a)
#def_input(b)
#show_var(a)
#show_var(b)
print("int64_t ts=readTSCp();")
print(C.code)
print("int64_t te=readTSCp();")
print('printf("cycle = %d\\n",int(te-ts));')
show_output256(c)

#show_var(c)
print("}")
