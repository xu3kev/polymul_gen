class Var:
    counter = 0
    all_var = set()

    def __init__(self, load_input = None):
        self.id = self.new_id()
        self.load_input = load_input
        self.all_var.add(self)

    def __repr__(self):
        return "v"+str(self.id)

    @classmethod
    def new_id(cls):
        id = cls.counter
        cls.counter += 1
        return id 
    
def load(x):
    if x.load_input:
        pass
    
def p(instr, dst, src1, src2):
    print("{} = {}({},{});".format(str(dst), instr, str(src1), str(src2)))

def mul(a,b):
    load(a)
    load(b)
    c = [Var(),Var()]
    p("_mm256_mul_pd",c[i],a[i],b[i])
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

