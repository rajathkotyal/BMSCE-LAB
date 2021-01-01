import re

combinations=[[True,True,True],
              [True,True,False],
              [True,False,True],
              [True,False,False],
              [False,True,True],
              [False,True,False],
              [False,False,True],
              [False,False,False]]

variable={'p':0,'q':1, 'r':2}
priority={'~':3,'v':1,'^':2}

def input_rules():
    global kb,query
    kb=(input("Enter the knowledge base: "))
    query=(input("Enter the query: "))
    kb=convert(kb)

def toPostfix(infix):
    stack = []
    postfix = ''
    for c in infix:
        if isOperand(c):
            postfix += c
        else:
            if isLeftParanthesis(c):
                stack.append(c)
            elif isRightParanthesis(c):
                operator = stack.pop()
                while not isLeftParanthesis(operator):
                    postfix += operator
                    operator = stack.pop()
            else:
                while (not isEmpty(stack)) and hasLessOrEqualPriority(c, peek(stack)):
                    postfix += stack.pop()
                stack.append(c)
    while (not isEmpty(stack)):
        postfix += stack.pop()

    return postfix

def _eval(i, val1, val2):
    if i == '^':
        return val2 and val1
    return val2 or val1


def evaluatePostfix(exp, comb):
    stack = []
    for i in exp:
        if isOperand(i):
            stack.append(comb[variable[i]])
        elif i == '~':
            val1 = stack.pop()
            stack.append(not val1)
        else:
            val1 = stack.pop()
            val2 = stack.pop()
            stack.append(_eval(i, val2, val1))
    return stack.pop()

def isOperand(c):
    return c.isalpha() and c != 'v'

def isLeftParanthesis(c):
    return c == '('

def isRightParanthesis(c):
    return c == ')'

def isEmpty(stack):
    return len(stack) == 0

def peek(stack):
    return stack[-1]

def hasLessOrEqualPriority(c1, c2):
    try:
        return priority[c1] <= priority[c2]
    except KeyError:
        return False

def convert(kb):
    kb=kb.split(' ')
    newKb = []
    for x in kb:
        if x.find("=>")!=-1:
            split=x.split('=>')
            x="(~("+split[0]+")v("+split[1]+"))"
            newKb.append(x)
        else:
            newKb.append("("+x+")")

    newKb = "^".join(newKb)
    print(newKb)
    return newKb

def CheckEntailment():
    input_rules()
    postfix_kb=toPostfix(kb)
    postfix_q=toPostfix(query)
    for combination in combinations:
        eval_kb=evaluatePostfix(postfix_kb,combination)
        eval_q=evaluatePostfix(postfix_q,combination)
        print(combination,":kb=",eval_kb,":q=",eval_q)
        if(eval_kb==True):
            if(eval_q==False):
                print("\nThe Knowledge base DOESNT ENTAIL the query!!\n")
                return False
    print("\nThe Knowledge base ENTAILS the query\n")

CheckEntailment()
