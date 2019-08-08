

def get_result(larger,smaller) :
    avg = sum(smaller) / len(smaller)

    # avg is smaller than smallest number
    if avg < larger[0] :
        return abs(sum(larger[0:len(smaller)])-sum(smaller))
    # avg is bigger than biggest number
    if avg > larger[len(larger)-1] :
        return abs(sum(larger[-(len(smaller)-1):])-sum(smaller))
    for i in range(len(larger)) :
        if larger[i] == avg : # avg is exactly same
            return get_numbers(larger,i,len(smaller), sum(smaller))
            
        elif larger[i] < avg and avg < larger[i+1] :
            # larger[i] or larger[i+1]
            return get_numbers(larger,i,len(smaller), sum(smaller))

def get_numbers(larger, base_index, length, sum_val) :
    if length % 2 == 0 :
        left = length // 2
        right = length // 2
        left,right = get_balanced_leftright(base_index,left,right,len(larger))
        return abs(sum(larger[left:right])-sum_val)
            
    elif length % 2 == 1 :
        left = length // 2 
        right = length // 2 + 1
        left, right = get_balanced_leftright(base_index,left,right,len(larger))
        
        left2 = length // 2 + 1
        right2 = length // 2
        left2, right2 = get_balanced_leftright(base_index,left2,right2,len(larger))
        return min(sum(larger[left:right])-sum_val,sum(larger[left2:right2])-sum_val)

def get_balanced_leftright(base_index, left, right, length):
    if base_index - left < 0:
        right += abs(base_index - left)
        left -= abs(base_index - left)
        return left, right

    elif base_index + right > length:
        left += abs(base_index - right)
        right -= abs(base_index - right)
        return left, right
    else :
        return left, right

n,m=map(int,input().split())
women = list(map(int,input().split()))
men = list(map(int,input().split()))

if n == m :
    print(abs(sum(women)-sum(men)))
else :
    women.sort()
    men.sort()
    if n > m : #women > men
        print(abs(get_result(women,men)))
    else : #women < men
        print(abs(get_result(men,women)))
