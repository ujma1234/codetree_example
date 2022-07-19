x,y = 0,0
dx,dy = [1,0,-1,0], [0,-1,0,1]

dir_num = 3
N = input()
cmd = {"R": 1, "L": -1, "F":2}

for i in N :
    if(i != "F") :
        dir_num = (dir_num + cmd[i]) % 4
    else :
        x, y = x + dx[dir_num], y + dy[dir_num]

print(x, y)