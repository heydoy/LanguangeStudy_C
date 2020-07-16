#Lab 04, Doy Kim, Thu 16 Apr, 2020
#주사위 게임 프로그램 

import easygui
import random

rolltime = 3
computer_dice = 0
my_dice = 0
result = ""

name = easygui.enterbox("Write your name")
#easygui.msgbox("Play rolling a dice", ok_button="Roll")
easygui.buttonbox("Play rolling a dice", choices=['Roll'])

while rolltime > 0 :
    
    dice = random.randint(1,6)
    
    
    my_dice = my_dice + dice
    #computer_dice = computer_dice + random.randint(1,6)

    
    rolltime = rolltime-1
    
    if rolltime >= 1 :
        #easygui.msgbox("You got {} \n{} times left".format(dice, rolltime),ok_button="Roll")
        easygui.buttonbox("You got {} \n{} times left".format(dice, rolltime),choices=['Roll'])
        
    elif rolltime == 0 :
        #easygui.msgbox("You got {} \nNo more chance ..".format(dice), ok_button="Show the result")
        easygui.buttonbox("You got {} \nNo more chance ..".format(dice), choices=['Show the result'])


#computer_dice = random.randint(3,18)    
computer_dice = random.randint(1,18)

if my_dice > computer_dice :
    result = "You won ^0^"
elif my_dice < computer_dice :
    result = "You lose T^T"
else :
    result = "You draw -o-"



easygui.msgbox("{}\'s Final Score : {} \nComputer Score : {} \n{}".format(name, my_dice, computer_dice, result))

