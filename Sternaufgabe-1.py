from math import inf as inf

n,m = map(int, input().split())


dist = []

for i in range(0, n):
    temp = []
    for j in range(0, n):
        if i == j:
            temp.append(0)
        else:
            temp.append(inf)
    dist.append(temp)


for i in range(0, m):
    u, v, w = map(int, input().split())
    dist[u-1][v-1] = w

for r in range(0, n):
    for t in range(0, n):
        for z in range(0, n):
            if(dist[t][r] != inf) and (dist[r][z] != inf):
                if dist[t][z] > dist[t][r] + dist[r][z]:
                    dist[t][z] = dist[t][r] + dist[r][z]

for i in range(0, n):
    for j in range(0, n):
        if j== n-1:
            print(dist[i][j])
        else:
            print(dist[i][j], end=" ")