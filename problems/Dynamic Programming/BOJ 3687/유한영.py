number_tail = [None,None,1,7,4,2,6,8,10,18,22,20,28,68,88]
number_head = [None,1,1,2,2,2,6,8]

def print_min(num_min):
    if num_min < 15 :
        print(number_tail[num_min],end = ' ')
        return
    else :
        base_num = num_min - 7 * ( ( num_min // 7 ) - 1 )
        if base_num == 10 and num_min >= 17 :
            print('200',end = '')
            print('8'*((num_min // 7)-2),end = ' ')
        else :
            print(number_tail[base_num],end='')
            print('8'*((num_min // 7)-1),end = ' ')
    
    
def print_max(num_max):
    if num_max % 2 == 1 :
        print('7', end = '')
        print_max(num_max - 3)
    else :
        print('1' * ( num_max // 2 ))
        return
    

test_cases = int(input())
for _ in range(test_cases) :
    n = int(input())
    print_min(n) # min part
    print_max(n) # max part
