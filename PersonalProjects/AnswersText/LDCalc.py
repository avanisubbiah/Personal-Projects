# install with pip3 install python-Levenshtein
from Levenshtein import distance
from collections import OrderedDict


# Class for Answer Reader
class answerReader:
    # Method to read a text file: "txtName"
    def reader(txtName):
        with open(txtName) as txt:
            aDict = OrderedDict()
            # Reading all lines in A.txt into keysAndVals
            keysAndValsOG = txt.readlines()
            i = 0
            key = []  # Seperate array to store keys
            val = []  # Seperate array to store values

            ii = 0
            semiPos = 0
            keysAndVals = keysAndValsOG

            for value in keysAndValsOG[0]:
                if keysAndValsOG[0][ii] == ';':
                    semiPos = ii
                elif keysAndValsOG[0][ii] == ':':
                    if (semiPos != 0):
                        keysAndVals[0] = keysAndValsOG[0][0:semiPos] + '|' + keysAndValsOG[0][(semiPos+1):]                
                ii += 1
            keysAndVals = keysAndValsOG[0].split("|")

            for value in keysAndVals:
                keyVal1st = keysAndVals[i].split(":")
                val1st = keyVal1st[1].split(";")
                keyVal = []
                keyVal.append(keyVal1st[0])
                j = 0
                for value in val1st:
                    keyVal.append(val1st[j])
                    j += 1
                j = 0
                key.append(keyVal[0].rsplit())
                innerValList = []
                j = 0
                for value in keyVal:
                    if(j != 0):
                        innerValList.append(keyVal[j].rsplit())
                    j += 1
                val.append(innerValList)
                i += 1
            i = 0
            i = 0
            # TODO Remove test prints when done
            # print(key)
            # print(val)
            # For every value in key update dictionary with next key and value
            for value in key:
                keyNow = str(key[i])
                aDict.update({keyNow: val[i]})
                i += 1
            # TODO Remove test print loop when done
            '''
            print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
            for keys,values in aDict.items():
                print(keys)
                print(aDict[keys])
            '''
        return aDict


class levenshteinD:
    # Method to calculate the distance between the values between two dictionaries
    def distanceCalc():
        # Initializing variables and calling reader
        realADict = answerReader.reader("realA.txt")
        aDict = answerReader.reader("A.txt")
        distList = []
        totAns = 0
        avgDistDouble = None

        frameAnsCombList = []
        for key in realADict:
            frameAnsCombinations = [[real, gen] for real in realADict[key] for gen in aDict[key]]
            #print(frameAnsCombinations)
            frameAnsCombList.append(frameAnsCombinations)
        keyInd = 0
        for key in frameAnsCombList:
            ansMacMatchInd = 0
            for ansMacMatch in frameAnsCombList[keyInd]:
                frameAnsCombList[keyInd][ansMacMatchInd] = [[real, gen] for real in frameAnsCombList[keyInd][ansMacMatchInd][0] for gen in frameAnsCombList[keyInd][ansMacMatchInd][1]]
                ansMacMatchInd += 1
            keyInd += 1
        '''
        print("-----------------------")
        print(frameAnsCombList[0][0][0])
        '''
        distList = frameAnsCombList
        keyInd = 0
        for key in frameAnsCombList:
            ansMacMatchInd = 0
            for ansMacMatch in frameAnsCombList[keyInd]:
                ansInnMatchInd = 0
                for ansInnMatch in frameAnsCombList[keyInd][ansMacMatchInd]:
                    '''
                    print("--------------------------------")
                    print(keyInd)
                    print(ansMacMatchInd)
                    print(ansInnMatchInd)
                    print(distance(distList[keyInd][ansMacMatchInd][ansInnMatchInd][0],distList[keyInd][ansMacMatchInd][ansInnMatchInd][1]))
                    print(distList)
                    '''
                    distList[keyInd][ansMacMatchInd][ansInnMatchInd] = distance(distList[keyInd][ansMacMatchInd][ansInnMatchInd][0],distList[keyInd][ansMacMatchInd][ansInnMatchInd][1])
                    ansInnMatchInd += 1
                ansMacMatchInd += 1
            keyInd += 1

        keyInd = 0
        for key in distList:
            flatRealADictStr = []
            for sublist in distList[keyInd]:
                for val in sublist:
                    flatRealADictStr.append(val)
            distList[keyInd] = flatRealADictStr
            keyInd += 1
        #print("---------------------------------------------------")
        #print(distList)

        keyInd = 0
        minI = 0
        for key in distList:
            for i in range(len(distList[keyInd])):
                # Find the minimum element in remaining
                minI = i
                for j in range(i+1, len(distList[keyInd])):
                    if distList[keyInd][minI] > distList[keyInd][j]:
                        minI = j
                # Swap the found minimum element with minI       
                distList[keyInd][i], distList[keyInd][minI] = distList[keyInd][minI], distList[keyInd][i] 
        #print(distList)

        totalWord = []
        for key in realADict:
            totalWordInKey = []
            for val in realADict[key]:
                #print(len(realADict[key]))
                totalWordInKey.append(len(realADict[key]))
            totalWord.append(sum(totalWordInKey))
        #print(totalWord)

        distListSumOfKey = []
        keyInd = 0
        for key in distList:
            #print(distList[keyInd][0:totalWord[keyInd]])
            distListSumOfKey.append(sum(distList[keyInd][0:totalWord[keyInd]]))
            keyInd += 1
        #print(distListSumOfKey)
        #print(frameAnsCombList[0][0])
        #print([[real, gen] for real in frameAnsCombList[0][0][0] for gen in frameAnsCombList[0][0][1]])
        # Iterating and calculating distance for each key in realADict
        '''
        for key in realADict:
            
            # Flattening realADict values for this key into one list
            flatRealADictStr = []
            for sublist in realADict[key]:
                for val in sublist:
                    flatRealADictStr.append(val)
            realADict[key] = flatRealADictStr
            #print(" ".join(realADict[key]))
            # Flattening aDict values for this key into one list
            flatADictStr = []
            for sublist in aDict[key]:
                for val in sublist:
                    flatADictStr.append(val)
            aDict[key] = flatADictStr
            #print(" ".join(aDict[key]))
            # Appending the distance between
            print(" ".join(" ".join(realADict[key])))
            print(" ".join(" ".join(aDict[key])))
            distList.append( distance( " ".join(" ".join(realADict[key])), " ".join(" ".join(aDict[key])) ) )
        '''
        # Calculating and Returning average distance
        if (len(distListSumOfKey) != 0):
            avgDistDouble = sum(distListSumOfKey)/len(distListSumOfKey)
        
        return avgDistDouble

print("Import levenshteinD and answerReader classes instead and run levenshteinD.distanceCalc()")
avgDist = levenshteinD.distanceCalc()
print("The error of the solution is: %f" %(avgDist))