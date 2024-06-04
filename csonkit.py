rawFile = open("musicin.txt")

rawFileData = rawFile.read()

dataOut = ""

counter = 0
for item in rawFileData.split(","):
    dataOut += f"{item}, "

    counter += 1
    if (counter > 30000):
        break

fileOut = open("musicout.txt", "w")
fileOut.write(dataOut)
fileOut.close()
