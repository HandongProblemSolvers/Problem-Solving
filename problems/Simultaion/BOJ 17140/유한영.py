def get_colum(row, col) :
    global rows
    cols = []
    for i in range(col) :
        col = []
        for j in range(row) :
            col.append(rows[j][i])
        cols.append(col)
    return cols
    
def compute_rows() :
    sorted_num = {}
    for i in range(len(cols)) :
        if rows[i] != 0 and sorted_num.get(rows[i]) == None :
            sorted_num[rows[i]] = rows[i].count(rows[i])
    result = [v[0] for v in sorted(sorted_num.items(), key = lambda(k,v) : (-v,k))]

def compute_cols() :
    rows = get_colum(row,col)
    sorted_num = {}
    for i in range(len(cols)) :
        if rows[i] != 0 and sorted_num.get(rows[i]) == None :
            sorted_num[rows[i]] = rows[i].count(rows[i])
    result = [v[0] for v in sorted(sorted_num.items(), key = lambda(k,v) : (-v,k))]

r,c,k = map(int,input().split())
rows = []
cols = []
for _ in range(3) :
    rows.append(list(map(int,input().split())))
cols = get_colum(3,3)

time = 0
while time <= 100 :
    time += 1
    if len(rows) >= len(cols) : #R연산
        compute_rows()
    else : #C연산
print(rows,cols)
