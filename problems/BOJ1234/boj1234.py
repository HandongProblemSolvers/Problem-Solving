import math

def avaialbe_tree(level, red, green, blue, value) :
    global result
    if red + green + blue < level :
        return
    if red >= level :
        if level == 1 :
            if value == 0 :
                result += 1
            else : 
                result += value 
            return
        else : 
            if value == 0 :
                value += 1
                avaialbe_tree(level-1, red-level, green, blue, value)
                value -= 1
            else :
                avaialbe_tree(level-1, red-level, green, blue, value)
    if green >= level :
        if level == 1 :
            if value == 0 :
                result += 1
            else : 
                result += value
            return
        else : 
            if value == 0 :
                value += 1
                avaialbe_tree(level-1, red, green-level, blue, value)
                value -= 1
            else :
                avaialbe_tree(level-1, red, green-level, blue, value)

    if blue >= level :
        if level == 1 :
            if value == 0 :
                result += 1
            else :
                result += value
        else : 
            if value == 0 :
                value += 1
                avaialbe_tree(level-1, red, green, blue-level, value)
                value -= 1
            else : 
                avaialbe_tree(level-1, red, green, blue-level, value)
    
    if level % 2 == 0 : # 2 4 6 8 
        level_div = level // 2
        if red >= level_div and green >= level_div :
            if value != 0 :  
                value *= math.factorial(level) // ( math.factorial( level_div ) ** 2 )
                avaialbe_tree(level-1,red - level_div , green - level_div, blue, value)
                value = value // ( math.factorial(level) // ( math.factorial( level_div ) ** 2 ) )
            else :
                value += math.factorial(level) // ( math.factorial( level_div ) ** 2 )
                avaialbe_tree(level-1,red - level_div , green - level_div, blue, value)
                value -= math.factorial(level) // ( math.factorial( level_div ) ** 2 )

        if red >= level_div and  blue >= level_div :
            if value != 0 :  
                value *= math.factorial(level) // ( math.factorial( level_div ) ** 2 )
                avaialbe_tree(level-1,red - level_div , green, blue - level_div, value)
                value = value // ( math.factorial(level) // ( math.factorial( level_div ) ** 2 ) )
            else :
                value += math.factorial(level) // ( math.factorial( level_div ) ** 2 )
                avaialbe_tree(level-1,red - level_div , green, blue - level_div, value)
                value -= math.factorial(level) // ( math.factorial( level_div ) ** 2 )
        if green >= level_div and  blue >= level_div :
            if value != 0 : 
                value *= math.factorial(level) // ( math.factorial( level_div ) ** 2 )
                avaialbe_tree(level-1,red, green - level_div, blue - level_div , value)
                value = value // ( math.factorial(level) // ( math.factorial( level_div ) ** 2 ) )
            else :
                value += math.factorial(level) // ( math.factorial( level_div ) ** 2 )
                avaialbe_tree(level-1,red, green - level_div, blue - level_div , value)
                value -= math.factorial(level) // ( math.factorial( level_div ) ** 2 )
        
    elif level % 3 == 0 : # 3 6 9
        if red >= level // 3 and green >= level // 3 and blue >= level // 3 :
            if value != 0 : 
                value *= math.factorial(level) // ( math.factorial( level // 3 ) ** 3 )
                avaialbe_tree(level-1, red - (level // 3), green - (level // 3), blue - (level // 3) , value)
                value = value // ( math.factorial(level) // ( math.factorial( level // 3 ) ** 3 ) )
            else :
                value += math.factorial(level) // ( math.factorial( level // 3 ) ** 3 )
                avaialbe_tree(level-1, red - (level // 3), green - (level // 3), blue - (level // 3) , value)
                value -= math.factorial(level) // ( math.factorial( level // 3 ) ** 3 )
            

result = 0
N,R,G,B = map(int,input().split())
avaialbe_tree(N,R,G,B,0)
print(result)