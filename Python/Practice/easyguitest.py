import easygui

selected_language = easygui.buttonbox("What is your favorite programming language?",choices=['c','java','python'])

easygui.msgbox("you picked "+selected_language)

subject = easygui.enterbox("What is your favorite class?")
easygui.msgbox("your fav is {}".format(subject))

selection = ["김밥","돌솥비빔밥","돈까스","떡볶이","라면"]
reply = easygui.choicebox("무얼 드시겠습니까?",choices=selection)
easygui.msgbox(reply+"을 주문하셨습니다.")

