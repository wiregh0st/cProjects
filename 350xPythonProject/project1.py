#program will check for file copies
import os
import pathlib
import re
import sys

textFiles = []
#get path of all files in directory
filesInDir = os.listdir()
dirPath = pathlib.Path().absolute()
print(dirPath)
#get input from user for which file to check other files against
userFileName = ''
userFileExt = []
while userFileName == '':
    userFileName = input("Please input the name of the text file for which you would like to check for duplicates: ")
if userFileName.find('.') == -1:  #-1 means userFileName string didn't contain period, extension was not entered or entered improperly. add full path if true.
    userFilePath = str(dirPath) + '\\' + userFileName + '.txt'
else:
    tempExt = re.split("(.txt)", userFileName)  #check user input file for .txt extension
    userFileExt = tempExt[-2:]
    userFileExt[-1] = userFileExt[-1].strip()
    if userFileExt and userFileExt[0] == '.txt' and userFileExt[-1] == '':  #if extension is .txt, add full path, else add .txt extension
        userFilePath = str(dirPath) + '\\' + userFileName
    else:
        userFilePath = str(dirPath) + '\\' + userFileName + '.txt'
#read userFile lines
try:
    userFile = open(userFilePath, mode='r')
except FileNotFoundError:
    sys.exit("The file you entered was not found. Please try again with a text file that exists.")
userFileLines = userFile.read()
userFile.close()
#iterate through file names in directory to grab absolute paths
for name in filesInDir:
    absPath = str(dirPath) + '\\' + name
    ext = os.path.splitext(absPath)
    if ext[1] == '.txt':
        textFiles.append(absPath)
#check file byte sizes
possibleDupe = []
for files in textFiles:
    if os.stat(files).st_size == os.stat(userFilePath).st_size and files != userFilePath:
        possibleDupe.append(files)
#iterate through possible duplicate files. Read lines of file, compare lines to user input file. If same, tell user.
for files in possibleDupe:
    dupeFile = open(files, mode='r')
    dupeFileLines = dupeFile.read()
    dupeFile.close()
    #check lines of files against each other for sameness
    if(dupeFileLines == userFileLines):
        print("File: " + "\"" + files + "\"" + " is duplicate.")
print('***********')




