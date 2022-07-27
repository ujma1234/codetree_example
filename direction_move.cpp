dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]
dir_str_to_num = {"W" : 0, "S" : 1, "N": 2, "E":3}
x, y = 0, 0

N = int (input())

for _ in range(N):
    d, dis = input().split()

    dir_num = dir_str_to_num[d]

    x += dx[dir_num] * int(dis)
    y += dy[dir_num] * int(dis)

print(x, y)