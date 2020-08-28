def validate(a,lhs,lhs1):
    stacklist = []
    s = 0
    e = 0
    c = []
    i = 0


    while a[i] != "=":
        if s == 0 and a[i] == '(':
            stacklist.append('(')
            s = i
            c.append(s)
        elif a[i] == "(":
            stacklist.append('(')
        if a[i] == ")" and len(stacklist) == 0:
            return False
        elif a[i] == ')':
            stacklist.pop()
        if a[i] == ',':
            c.append(i)
        e = i
        i+=1
    e -= 1
    c.append(e)
    al = len(a)
    stacklist1 = []
    s1 = 0
    e1 = 0
    c1 = []
    for j in range(e+4,al-1):
        if s1 == 0 and a[j] == '(':
            stacklist1.append('(')
            s1 = j
            c1.append(s1)
        elif a[j] == "(":
            stacklist1.append('(')
        if a[j] == ")" and len(stacklist1) == 0:
            return False
        elif a[j] == ')':
            stacklist1.pop()
        if a[j] == ',':
            c1.append(j)
        e1 = j
    c1.append(e1)
    funcpred = a[0:s]
    for k in range(1,len(c)):
        lhs.append(a[c[k-1]+1:c[k]])
    funcpred1 = a[e+4:s1]
    for k in range(1,len(c1)):
        lhs1.append(a[c1[k-1]+1:c1[k]])

    uppercount = 0
    for k in range(al):
        if a[k].isupper():
            uppercount = uppercount + 1
    
    if len(stacklist) == 0 and len(stacklist1) == 0:
        if funcpred == funcpred1 and uppercount >= len(c)-2 and len(c) == len(c1):
            return True 
        else:
            return False
    else:
        return False


def checkforfunction(s):
    sl = len(s)
    for i in range(sl):
        if s[i] == '(' or s[i] == ')':
            return True
    return False

def validateatoms(a,b,upd):
    stringforvalidation = a + " = " + b + "."
    lhs2 = []
    rhs1 = []
    if validate(stringforvalidation,lhs2,rhs1):
        a = lhs2[0]
        b = rhs1[0]
        upd.append(a)
        upd.append(b)
        return True
    else:
        print("Fail4")
        return False
def output(lhs,lhs1):
    for k in range(len(lhs)):
        if checkforfunction(lhs[k]) and checkforfunction(lhs1[k]):
            upd = []
            if validateatoms(lhs[k],lhs1[k],upd):
                lhs[k] = upd[0]
                lhs1[k] = upd[1]
            else:
                return False
        if checkforfunction(lhs[k]) and checkforfunction(lhs1[k]) == False:
            temp = lhs[k]
            lhs[k] = lhs1[k]
            lhs1[k] = temp

        if lhs[k].islower() and lhs1[k].isupper:
            temp = lhs[k]
            lhs[k] = lhs1[k]
            lhs1[k] = temp
    return True
        
def finaloutput(lhs,rhs):
    for k in range(len(lhs)):
        stringa = lhs[k]
        stringb = rhs[k]
        for j in range(len(lhs)):
            for i in range(len(rhs[j])):
                if rhs[j][i] == stringa:
                    conl = list(rhs[j])
                    conl[i] = stringb
                    rhs[j] = "".join(conl)

             
def main():
    run = True
    inputfact = ""
    while(run):
        print("?- ",end="")
        factfun = str(input())
        if factfun == "abort" :
            run = False
        else:
            inputfact = inputfact + factfun 
            inputfactl = len(inputfact)

            if inputfact[inputfactl-1] == ".":
                lhs = []
                rhs = []
                if validate(inputfact,lhs,rhs) == False:
                    print("?- false")
                    run = False
                else:
                    if output(lhs,rhs) == False:
                        print("?- false")
                    else:
                        finaloutput(lhs,rhs)
                        for k in range(len(lhs)):
                            print(lhs[k],"=",rhs[k])
                        run = False 

if __name__ == "__main__":
    main()

