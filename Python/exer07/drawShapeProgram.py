import easygui
import turtle

turtle.setup(width=800, height=800)
circleradius=25
rectsize=50

choice = str(easygui.buttonbox("모양을 선택하세요", choices=['circle','rectangle']))
num = int(easygui.enterbox("개수를 입력하세요"))
t = turtle.Pen()

if choice == 'circle':
    for h in range(num) :
        t.down()
        t.circle(circleradius)
        t.up()
        t.forward(circleradius*2)
    
else :
    for i in range(num) :
        for j in range(4) :
            t.down()
            t.left(90)
            t.forward(rectsize)
            
        t.up()
        t.forward(rectsize)
    
