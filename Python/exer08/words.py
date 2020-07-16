'''
김도이 1815364
Lab08 : 과제 2 영어단어장 프로그램
'''
dictionary = []

def print_menu() :
    print('')
    print('*'*50)
    print('*',' '*12,'Sookmyung Dictionary',' '*12,'*')
    print('*'*50)

    print(' '*14,'1.Save words')
    print(' '*14,'2.Delete words')
    print(' '*14,'3.Print all words')
    print(' '*14,'4.Exit')

    print('='*50)
    
def save_words() :
    print("Enter word to save. (Press \'Enter\' key to finish)\n") 
    while True : 
        save = str(input('Word : '))

        if len(save) == 0 :
            return
        
        if save in dictionary :
            print("Already Exist")
            continue

        else :
            dictionary.append(save)

def delete_words() :
    print("Enter word to delete.")
    while True :
        delete = str(input("Word : "))

        if delete not in dictionary :
            print("No exist")
            continue

        else :
            dictionary.remove(delete)
            print("Deletion Complete")
            return


def print_all() :
    print('')
    for i in dictionary :
        print(i)


# 메인 시작 
while True :

    print_menu()
    num = input("Select >> ")

    if int(num) == 1 :
        save_words()

    elif int(num) == 2 :
        delete_words()

    elif int(num) == 3 :
        print_all()

    elif int(num) == 4 :
        break

    else :
        print("You entered wrong menu!")
        continue
        

