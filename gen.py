class Code:
    code=""
    
C = Code()

class Var:
    counter = 0
    all_vars = set()

    def __init__(self, load_input = None):
        self.id = self.new_id()
        self.load_input = load_input
        self.all_vars.add(self)

    def __repr__(self):
        return "v"+str(self.id)

    @classmethod
    def new_id(cls):
        id = cls.counter
        cls.counter += 1
        return id 
    
def load(x):
    for v in x:
        if v.load_input is not None:
            C.code+=("{} = _mm256_load_pd({}+4*{});\n".format(v,v.load_input[0],v.load_input[1]))
    
def p(instr, dst, src1, src2):
    C.code+=("{} = {}({},{});\n".format(str(dst), instr, str(src1), str(src2)))

def mul(a,b):
    load(a)
    load(b)
    c = [Var(),Var()]
    C.code+=("MUL256({},{},{},{});\n".format(c[0],c[1],a[0],b[0]))
    
    #print("{}={}*{}".format(c[0],a[0],b[0]))
    #print("{}=0".format(c[1]))
    return c
        
def add(a,b):
    n = len(a)
    load(a)
    load(b)
    c = [Var() for i in range(n)]
    for i in range(n):
        p("_mm256_add_pd",c[i],a[i],b[i])
        #print("{}={}+{}".format(c[i],a[i],b[i]))
    return c

def sub(a,b):
    n = len(a)
    load(a)
    load(b)
    c = [Var() for i in range(n)]
    for i in range(n):
        p("_mm256_sub_pd",c[i],a[i],b[i])
        #print("{}={}-{}".format(c[i],a[i],b[i]))
    return c

def lower(x):
    return x[0:len(x)//2]

def higher(x):
    return x[len(x)//2::]

def polymul(a,b):
    return schoolbook(a,b)

def schoolbook(a,b):
    n = len(a)
    if n>=2:
        n = len(a)
        MUL = schoolbook
        a0 = lower(a)
        a1 = higher(a)
        b0 = lower(b)
        b1 = higher(b)

        c0 = MUL(a0,b0)
        d10 = MUL(a1,b0)
        d01 = MUL(a0,b1)
        c1 = add(d01,d10)
        c10 = add(higher(c0),lower(c1)) 
        c2 = MUL(a1,b1)
        c11 = add(lower(c2),higher(c1))
        return lower(c0)+c10+c11+higher(c2)

    elif n==1:
        c = mul(a,b)
        return c
        
def karatsuba(a,b):
    n = len(a)
    if n>=2:
        n = len(a)
        MUL = karatsuba
        a0 = lower(a)
        a1 = higher(a)
        b0 = lower(b)
        b1 = higher(b)

        c0 = MUL(a0,b0)
        d1 = add(a0,a1)
        d2 = add(b0,b1)
        d3 = MUL(d1,d2)
        c2 = MUL(a1,b1)
        d4 = sub(d3,c0)
        c1 = sub(d4,c2)
        c10 = add(higher(c0),lower(c1)) 
        c11 = add(lower(c2),higher(c1))
        return lower(c0)+c10+c11+higher(c2)

    elif n==1:
        c = mul(a,b)
        return c


MUL_MACRO="""#define MUL256(e0,e1,a,b) \
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
"""

