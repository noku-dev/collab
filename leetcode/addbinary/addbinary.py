class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        result = list()
        lena = len(a)
        lenb = len(b)
        carry = False
        while lena + lenb > 0:
            vala = 0
            valb = 0
            if lena > 0:
                vala = int(a[lena - 1])
                lena -= 1
            if lenb > 0:
                valb = int(b[lenb - 1])
                lenb -= 1
            val = vala + valb
            if carry:
                val += 1
                carry = False
            if val > 1:
                carry = True
                val -= 2
            result.insert(0, str(val))
        if carry:
            result.insert(0, '1')
        s = ""
        return s.join(result)
