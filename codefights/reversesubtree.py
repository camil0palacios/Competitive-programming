import copy

def reverseToSort(inputArray):
    for i in range(len(inputArray)):
        j = i+1
        print(i)
        while j <= len(inputArray):
            aux1 = copy.deepcopy(inputArray)
            aux2 = aux1[i:j]
            aux2.reverse()
            aux1[i:j] = aux2
            print(aux2)
            print(aux1)
            for x in range(len(aux1)-1):
                if aux1[x] <= aux1[x+1]:
                    if x+1 == len(aux1)-1:
                        return True
                    continue
                else:
                    break
            j+=1
    return False

s = [-1, 5, 4, 3, 2, 8]
s1 = [19, 32, 23]
reverseToSort([19, 32, 23])
