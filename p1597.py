s = input()
li = s.split(';')
val_dict = {}


def is_num(val):
    res = True
    try:
        num = int(val)
    except:
        res = False
    return res


for idx in range(len(li)):
    if len(li[idx].strip()) == 0:
        continue
    key = li[idx].split(':=')[0].strip()
    val = li[idx].split(':=')[1].strip()

    if len(val) == 0:
        val_dict[key] = 0
        continue

    if is_num(val):
        val_dict[key] = val
        continue

    if val in val_dict.keys():
        val_dict[key] = val_dict[val]
        continue

for key in val_dict.keys():
    print('{}'.format(val_dict[key]), end=' ')
