import turtle

turtle.setup(width=500, height=500)


t = turtle.Pen()
t.width(4)

colorlist = ['red', 'blue', 'green', 'black']
num = 0

for i in range(0, 365, 12):
    t.forward(i)
    t.left(120)
    num = num + 1;
    t.pencolor(colorlist[num%4])
    
