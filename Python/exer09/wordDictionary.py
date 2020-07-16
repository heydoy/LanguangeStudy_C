'''
김도이 1815364
Lab09 / 과제 1 영어사전 프로그램
'''
dictionary = {}
scores = []

#메뉴 출력
def print_menu() :
    print('')
    print('*'*50)
    print('*',' '*12,'Sookmyung Dictionary',' '*12,'*')
    print('*'*50)

    print(' '*14,'1.Save words')
    print(' '*14,'2.Delete words')
    print(' '*14,'3.Print all words')
    print(' '*14,'4.Search word')
    print(' '*14,'5.Word Test')
    print(' '*14,'6.Show Test Score')
    print(' '*14,'7.Exit')

    print('='*50)

#단어, 뜻 저장
def save_words() :
    print("Enter word to save. (Press \'Enter\' key to finish)\n") 

    while True : 
        word = str(input('Word : '))
        
        if len(word) == 0 :
            return
        
        if word in dictionary :
            print("Already Exist")
            continue

        else :
            while True :
                mean = str(input('Mean : '))
                if len(mean) == 0 :
                    print("Enter word's meaning to save.")
                    continue
                else :
                    dictionary[word] = mean
                    break

#단어 삭제   
def delete_words() :
    print("Enter word to delete.\n")
    while True :
        delete = str(input("Word : "))

        if delete not in dictionary :
            print("No such words")
            continue

        else :
            del dictionary[delete]
            print("Deletion Complete")
            return


#저장한 내용 모두 보여주기 
def print_all() :
    print('')
    for word in dictionary :
        print(word, '\t', dictionary[word])


def search_word() :
    print("Enter word to search\n")

    query = str(input('word : '))

    if query not in dictionary :
        print("{} is not found".format(query))

    else :
        print(query, "\t", dictionary[query])


def word_test() :
    score = 0
    print('')
    for word in dictionary :
        answer = str(input('{} : '.format(word)))
        if answer == dictionary[word] :
            print("Correct!")
            score += 1
        else :
            print("Wrong..")
        print('')

    print("You got {} answers.".format(score))
    scores.append(score)
    
    

def show_score() :
    
    scores.sort(reverse = True)
    print('')
    print('\tScoreBoard')
    print('='*30)
    for i, score in enumerate(scores) :
        print('\t{} rank\t{} answers'.format(i+1, score))



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
        search_word()
    
    elif int(num) == 5 :
        word_test()
    
    elif int(num) == 6 :
        show_score()
    
    elif int(num) == 7 :
        print("Thanks for using dictionary")
        break

    else :
        print("You entered wrong menu!")
        continue
        

