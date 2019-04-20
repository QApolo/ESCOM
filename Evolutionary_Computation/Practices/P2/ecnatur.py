from Tkinter import *
import math


def ec(w,x,y,l,a,sl,da,n):
    if n==0:
        return

    color='black'

    if n>5:
        color='brown'
    elif n>2:
        color='green'
    elif n>0:
        color='white'

    x2=x+l
    y2=y
    ar=math.radians(a)

    coseno=math.cos(ar)
    seno=math.sin(ar)
    xrot= (x2-x)*seno + (y2-y)*coseno
    yrot= (x2-x)*coseno - (y2-y)*seno

    x2=xrot + x
    y2=yrot + y

    w.create_line(x,y,x2,y2,fill=color)
##1
    #ec(w,x2,y2,l*sl,a-da,sl,da,n-1)
    #ec(w,x2,y2,l*sl,a+da,sl,da,n-1)
    #ec(w,x2,y2,l*sl,a,sl,da,n-1)

##2
    #ec(w,x,y,l*sl,a-da,sl,da,n-1)

##3
    #if(y>280):return
    #for i in range(1, ): este no va
       #ec(w,x2,y2,l*sl,a-i*da,sl,da,n-1)
    #ec(w,x2,y2,l*sl,a-2*da,sl,da,n-1)
##    ec(w,x2,y2,l*sl,a-3*da,sl,da,n-1)

##4
    #w.create_oval((x-l/2),(y-l/2),(x+l/2),(y+l/2),fill='white') 
    #ec(w,x2,y2,l*sl,a-da,sl,da,n-1)
    #ec(w,x2,y2,l*sl,a-2*da,sl,da,n-1)
    #ec(w,x2,y2,l*sl,a-3*da,sl,da,n-1)

##5
    ec(w,x2,y2,l+sl,a+da,sl,da,n-1)
    return

master = Tk()

xmax=500
ymax=500

w = Canvas(master, width=xmax, height=ymax)
w.pack()

##1
#ec(w,250,480,150,180,0.7,20,8)

##2
#ec(w,250,250,150,180,0.97,2,50)

##3
#ec(w,10,280,150,120,0.8,20,5)

##4
#ec(w,10,180,150,120,0.8,30,10)

##5
ec(w,150,350,10,30,1,50,993)


mainloop()
