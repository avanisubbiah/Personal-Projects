import csv
import re
from collections import OrderedDict


def readGroundTruthCSV(indoorCSVDict = OrderedDict()):
    # Reading CSV file 'indoorTxt.csv'
    with open ('indoorTxt.csv') as indoorCSV:

        # Reading file and creating an ordered dicitonary
        indoorCSVReader = csv.DictReader(indoorCSV)
        #indoorCSVDict = OrderedDict()

        # For every row in indoorCSVReader add a new entry into indoorCSVDict
        for row in indoorCSVReader:
            indoorCSVDict[int(row['num'])] = [row['integerInFrame'], row['stringInFrame']]

        # Test print of all values stored in the dictionary
        for keys,values in indoorCSVDict.items():
            print(keys)
            print(indoorCSVDict[keys])
        
        # Test of list indexing with dicionary keys
        print(indoorCSVDict[1][0])
    return indoorCSVDict

def readQustionsCSV(indoorCSVDict):
    questionsCSVDict = OrderedDict()
    with open ('questions.csv') as questionsCSV:

        # Reading file and creating an ordered dicitonary
        questionsCSVReader = csv.DictReader(questionsCSV)

        # For every row in indoorCSVReader add a new entry into questionsCSVDict
        for row in questionsCSVReader:
            questionsCSVDict[int(row['num'])] = [row['question'], row['answer']]

        # Test print of all values stored in the dictionary
        for keys,values in questionsCSVDict.items():
            print(keys)
            print(questionsCSVDict[keys])
        
        # Test of list indexing with dicionary keys
        print(questionsCSVDict[1][0])

    with open ('questionsWithGroundTruthAns.csv', 'w') as questionsCSV:
        questionFields = ['num','question','answer']
        questionsCSVWriter = csv.writer(questionsCSV)
        questionsAnswersCSVDict = OrderedDict()

        for keys,values in questionsCSVDict.items():
            answerString = re.sub(questionsCSVDict[keys][0] + " ","", indoorCSVDict[keys][1])
            questionsAnswersCSVDict[keys] = [questionsCSVDict[keys][0], answerString]
            print(questionsAnswersCSVDict[keys])
            questionsCSVWriter.writerow(questionsAnswersCSVDict[keys])
