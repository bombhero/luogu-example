org_h = []
n = int(input())

h_str = input()
h_li = h_str.split()
for h in h_li:
    org_h.append(int(h))

org_h.sort(reverse=True)

idx = 0
last_h = 0
total_ee = 0
while len(org_h) > 0:
    total_ee += (last_h-org_h[idx])**2
    last_h = org_h[idx]
    org_h.pop(idx)
    if idx == 0:
        idx = -1
    else:
        idx = 0
print(total_ee)
