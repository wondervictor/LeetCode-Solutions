class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        letters = {'q':-1, 'w':-1, 'e':-1, 'r':-1, 'y':-1, 't':-1, 'u':-1, 'i':-1,'o':-1,'p':-1,
                   'a':2, 's':2, 'd':2, 'f':2, 'g':2, 'h':2, 'j':2, 'k':2, 'l':2,
                   'z':7, 'x':7, 'c':7, 'v':7, 'b':7, 'n':7, 'm':7}
        result = []
        for word in words:
            s = word
            word = word.lower()
            length = len(word)
            counter = 0
            for one in word:
                counter += letters[one]
            if counter == - length or counter == 2*length or counter == 7 * length:
                result.append(s)
        return result
