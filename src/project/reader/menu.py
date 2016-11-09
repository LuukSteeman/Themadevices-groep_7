def showMenu(menus, question='Please select a option:'):
    print question
    strr = ''
    for i in range(0,len(menus)):
        strr += str(i+1) + ":" + menus[i][0] + "\n"
    x = raw_input(strr)
    try:
        x = int(x)-1
    finally:
        if(type(x) is int and x < len(menus) and x > -1):
             menus[x][1]()
        else:
            showMenu(menus, question=question+'\ninvalid input')
        
