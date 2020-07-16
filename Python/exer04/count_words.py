#Lab 04, Doy Kim, Thu 16 Apr, 2020
#단어 공부 프로그램 

import easygui

sentence = easygui.enterbox("Write a sentence.")
easygui.msgbox("You wrote \"%s\"" % (sentence))

word = easygui.choicebox("Choose your word to study.",choices=sentence.split(' '))

easygui.msgbox("Today\'s word :\n%s" % (word))

