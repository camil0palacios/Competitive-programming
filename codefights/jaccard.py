def spamClusterization(requests, ids, threshold):
    newr= []
    for i in requests:
        aux = i.lower().replace("!","").replace(".","").replace(",","").split(' ')
        newr.append(aux)
    jaccard = []
    for i in range(len(newr)):
        for j in range(len(newr)):
            if i != j:
                x = set(newr[i])
                y = set(newr[j])
                if len(x & y)/len(x | y) >= threshold:
                    Setids(jaccard,ids,i,j)
    jaccard.sort()
    for i in jaccard:
        i.sort()
    return jaccard
                    
def Setids(jaccard,ids,index1,index2):
    for i in jaccard:
        if ids[index1] in i and  not ids[index2] in i:
            i.append(ids[index2])
            return
        if ids[index2] in i and  not ids[index1] in i:
            i.append(ids[index1])
            return
        if ids[index1] in i and ids[index2] in i:
            return
    jaccard.append([ids[index1],ids[index2]])


requests = ["I need a new window.",
            "I really, really want to replace my window!",
            "Replace my window.",
            "I want a new window.",
            "I want a new carpet, I want a new carpet, I want a new carpet.",
            "Replace my carpet"]

ids = [374, 2845, 83, 1848, 1837, 1500]

threshold = 0.5

#print(spamClusterization(requests,ids,threshold))
