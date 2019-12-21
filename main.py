from gen import *
from random import randint

n = 8
a = [Var() for i in range(n)]
b = [Var() for i in range(n)]

def def_input(x):
    for v in x:
        print("{} = {}".format(v, randint(0,4)))

def show_var(x):
    print("print({})".format(",".join(str(v) for v in x)))


def_input(a)
def_input(b)
show_var(a)
show_var(b)
c = schoolbook(a,b)
show_var(c)


