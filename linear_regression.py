n=int(input("Enter the no of samples: "))
x={}
y={}
print("Enter first column: ")
for i in range (0,n):
    x[i]=float(input())

print("Enter second column: ")
for i in range (0,n):
    y[i]=float(input())

print("Samples are:\nX\t\tY\n")
for i in range (0,n):
    print(x[i],"\t\t",y[i])

xval=float(input("Enter the unknown samples- "))
sum_x=0 
sum_y=0 
sum_x2=0 
sum_xy=0
for i in range (0,n):
    sum_x += x[i]
    sum_y += y[i]
    sum_x2 += x[i]*x[i]
    sum_xy += x[i]*y[i]
  
regcoeff1 = (sum_y*sum_x2 - sum_x*sum_xy)/(n*sum_x2 - sum_x*sum_x)
regcoeff2 = (n*sum_xy - sum_x*sum_y)/(n*sum_x2 - sum_x*sum_x)

yval = regcoeff1 + regcoeff2*xval
print("For dataset, for x =",xval,"y=",yval)