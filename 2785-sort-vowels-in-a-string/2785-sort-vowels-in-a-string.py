class Solution:
    def sortVowels(self, s: str) -> str:
        
        lst = []

        for ch in s:
            c = ch.lower()
            if(c in ('a' , 'e' , 'i' , 'o' , 'u')):
                lst.append(ch)

        
        lst.sort()

        newStr = ""
        i = 0

        for ch in s:
            c = ch.lower()
            if(c in ('a' , 'e' , 'i' , 'o' , 'u')):
                newStr = newStr + lst[i]
                i = i + 1

            else:
                newStr = newStr + ch

        
        return newStr