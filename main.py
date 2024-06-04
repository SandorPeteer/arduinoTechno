file = open("data.txt")

rawFileData = file.read()

dataOut = ""

for item in rawFileData.split("\n"):
    dataOut += f"{item}, "

fileOut = open("dataout.txt", "a")
fileOut.write(dataOut)
fileOut.close()