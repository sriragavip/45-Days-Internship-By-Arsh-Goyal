import collections


class Solution:

    def minWindow(self, searchString: str, target: str) -> str:
        minSubString = ""
        foundCharCounter = collections.Counter()
        targetCharCounter = collections.Counter(target)
        leftPointer, rightPointer = 0, 0

        for rightPointer in range(len(searchString)):
            currentChar = searchString[rightPointer]
			
			# If the current character is part of the target character
            if currentChar in list(targetCharCounter.keys()):
                foundCharCounter[currentChar] += 1

            # While the current substring matches the target
            while (foundCharCounter & targetCharCounter) == targetCharCounter:
                currentWindow = rightPointer - leftPointer + 1
                if currentWindow < len(minSubString) or minSubString == "":
                    minSubString = searchString[leftPointer:rightPointer + 1]
                foundCharCounter[searchString[leftPointer]] -= 1
                leftPointer += 1

        return minSubString