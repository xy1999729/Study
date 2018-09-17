dials = [3,3,0,2,2,2,2,1,2]

def add(var):
    dials[var] += 1

def switch(var):
#    return {
#        '1': add(0), add(1), add(3), add(4)
#        '2': add(0), add(1), add(2)
#        '3': add(1), add(2), add(4), add(5)
#        '4': add(0), add(3), add(6)
#        '5': add(1), add(3), add(4), add(5), add(7)
#        '6': add(2),  add(5), add(8)
#        '7': add(3), add(4), add(6), add(7)
#        '8': add(6), add(7), add(8)
#        '9': add(4), add(5), add(7), add(8)
#}                    
    if var == 1:                        
        add(0)                      
        add(1)
        add(3)
        add(4)
    elif var == 2:
        add(0)
        add(1)
        add(2)
    elif var == 3:
        add(1)
        add(2)
        add(4)
        add(5)
    elif var == 4:
        add(0)
        add(3)
        add(6)
    elif var == 5:
        add(1)
        add(3)
        add(4)
        add(5)
        add(7)
    elif var == 6:
        add(2)
        add(5)
        add(8)
    elif var == 7: 
        add(3)
        add(4)
        add(6)
        add(7)
    elif var == 8: 
        add(6)
        add(7)
        add(8)
    elif var == 9: 
        add(4)
        add(5)
        add(7)
        add(8)

switch(2)

for dial in dials:
    print(dial)
