from Tkinter import *
import math
import random

def ec(w,x,y,l,a,sl,da,n, op):
    if n==0:
        return

    color='black'

    if n>5:
        color='brown'
    elif n>2:
        color='green'
    elif n>0:
        color='green'

    if op == 3:
        color = '#666633'
        if n == 4 or n == 3:
            color = 'white'
    elif op == 2:
        color = 'yellow'
    

    x2=x+l
    y2=y
    ar=math.radians(a)

    coseno=math.cos(ar)
    seno=math.sin(ar)
    xrot= (x2-x)*seno + (y2-y)*coseno
    yrot= (x2-x)*coseno - (y2-y)*seno

    x2=xrot + x
    y2=yrot + y
    if op != 4:
        w.create_line(x,y,x2,y2,fill=color)
##1
    if op == 1:
        ec(w,x2,y2,l*sl,a-da,sl,da,n-1, 1)
        ec(w,x2,y2,l*sl,a+da,sl,da,n-1, 1)
        ec(w,x2,y2,l*sl,a,sl,da,n-1, 1)
    elif op == 2:
##2
        ec(w,x,y,l*sl,a-da,sl,da,n-1, 2)

    elif op == 3:
##3
        if(y>280):return
        ec(w,x2,y2,l*sl,a-da,sl,da,n-1, 3)
        ec(w,x2,y2,l*sl,a-2*da,sl,da,n-1, 3)
        ec(w,x2,y2,l*sl,a-3*da,sl,da,n-1, 3)
    elif op == 4:

##4
        w.create_oval((x-l/2),(y-l/2),(x+l/2),(y+l/2),fill='white') 
        ec(w,x2,y2,l*sl,a-da,sl,da,n-1, 4)
        ec(w,x2,y2,l*sl,a-2*da,sl,da,n-1, 4)
        ec(w,x2,y2,l*sl,a-3*da,sl,da,n-1, 4)

##5
    elif op == 5:
        ec(w,x2,y2,l+sl,a+da,sl,da,n-1, 5)
    return

master = Tk()
xmax=1024
ymax=500

w = Canvas(master, width=xmax, height=ymax)
w.pack()
w.create_rectangle(0, 0, xmax, 230, fill ='#0099cc')
w.create_rectangle(0, 230, xmax, ymax, fill ='#333300')

##3 mountain 
ec(w,10,280,150,120,random.uniform(0.6,0.8),20,5, 3)
ec(w,200,280,150,120,0.8,20,5, 3)
ec(w,500,280,150,120,0.8,20,5, 3)

##1 trees
for tree in range(20, 1000, 40):
    ec(w,150+tree, 450 + random.randint(2, 30), 60, 180,random.uniform(0.4, 0.7), 30, 8, 1)
##4 clouds
for cloud in range(0, 400, 140):
    ec(w,10 + cloud, random.randint(0, 50),30,30,0.9,30,9, 4)
for cloud in range(700, 1200, 100):
    ec(w,10 + cloud, random.randint(0, 50),30,30,0.9,30,9, 4)
##2 sun
ec(w,xmax//2,100,150,180,0.90,33,50, 2)

mainloop()
