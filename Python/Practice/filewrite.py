def write_file(memolist):
    f = open('shoppingList.txt','w')
    for item in memolist :
        msg = item + '\n'
        f.write(msg)
    f.close()

def write_file_again(memolist):
    f = open('shoppingList.txt','a')
    for item in memolist :
        msg = item + '\n'
        f.write(msg)
    f.close()


mymemo = []

while True:
    print("Write an item to buy. Enter a blank line to exit: ")
    item = input()
    if len(item) == 0 :
        break
    mymemo.append(item)

write_file_again(mymemo)
print(len(mymemo), "items are written into file")

