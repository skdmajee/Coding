from collections import defaultdict

scramble = 'ehllotehotwolrd'
wordset = {'the','hello','world','to'}

def calchash(s, kv, ll):
    hk = 0
    for c in s:
        hk += ord(c)
    hk *= (kv+ll)
    return hk

def builddict(wordset):
#
#Creates a dictionary of words. Each entry has the string and the unique value 
#that is used to create the key
#
    wdict=defaultdict(list)
    kv = 1
    for word in wordset:
        hk = calchash(word, kv, len(word))
        wdict[hk].append(word)
        wdict[hk].append(kv)
        kv += 1

    return wdict


def unscramble(scramble, wdict):
#
# Look for each keys in the scrambled string. Find the position and 
# insert into a list
#
    wlist=[]
#Loop to srch all dict words in strint
    for k in wdict.keys():
        kv = wdict[k][-1]
        word = wdict[k][0]
        i = 0
    #Key aka word srch loop
        while ( i < len(scramble)):
            end = i + len(word)
            win = scramble[i:end]
            # cacl hash
            hk = calchash(win, kv, len(word))
            # check to see if it exists
            if hk not in wdict:
                # Shift to right and continue srching 
                i += 1
                if (i+len(word) <= len(scramble)):
                    continue
            else:
                # Found a match
                s = wdict[hk][0]
                tp = (i,s)
                wlist.append(tp)
                print ('found %s at %d'% (s,i))
                break;
    return(wlist)

def getkey(k):
    return k[0]

def main():
    
    wd = builddict(wordset)
    print wd
    wl = unscramble(scramble, wd)
    # Sort the list according to position number
    print wl
    a = sorted(wl, key=lambda wl:wl[0])
    #a = sorted(wl, key=getkey)
    print a

if __name__ == "__main__":
    main()


            
