#imports
import csv
import os
import glob
import matplotlib.pyplot as plt
#global vars
PlotArrayEyeCatching = [[0 for x in range(301)] for y in range(4)] 
PlotArrayNotEyeCatching = [[0 for x in range(301)] for y in range(4)]
#files
result = [i for i in glob.glob('*.{}'.format("csv"))]
#experimental Var-Params
experimentalVar=[0.2];
for file in result:
    valindex=0
    w, h = 3, 17;
    Matrix = [[0 for x in range(w)] for y in range(h)] 
    for val in experimentalVar:
        with open(file, 'r') as csvfile:
            testdatareader = csv.reader(csvfile, delimiter=' ', quotechar='|')
            i=0
            #transpose
            for row in testdatareader:
                j=0
                for item in row:
                    Matrix[j][i]=item
                    j+=1
                i+=1
            #encode and count
            for row in Matrix:
                if row[0]=='':
                    break
                if not float(row[2]) ==val:
                    continue

                if(float(row[0])<0):
                    if int(row[1])==1:
                        PlotArrayEyeCatching[valindex][int(float(row[0])*1000)+150]+=1
                    else:
                        PlotArrayNotEyeCatching[valindex][int(float(row[0])*1000)+150]+=1
                else:
                    if int(row[1])==0:
                        PlotArrayEyeCatching[valindex][int(float(row[0])*1000)+150]+=1
                    else:
                        PlotArrayNotEyeCatching[valindex][int(float(row[0])*1000)+150]+=1
        valindex+=1

#define x and y value too plot
exvarindex=0
graphX=[[] for x in range(4)]
graphY=[[] for x in range(4)]
for val in experimentalVar:
    index=0;
    for x in PlotArrayEyeCatching[exvarindex]:
        if(x>0 or PlotArrayNotEyeCatching[exvarindex][index]>0):
            graphX[exvarindex].append(index-150);
            graphY[exvarindex].append(x/(x+PlotArrayNotEyeCatching[exvarindex][index])*100)
        index+=1
    exvarindex+=1

#Plot max 4 graphs
plt.xlabel('Soas')
plt.ylabel('Percentage')
plt.plot(graphX[0], graphY[0],
        graphX[0], graphY[0], "oy",
        graphX[1], graphY[1], 
        graphX[1], graphY[1], "or",
        graphX[2], graphY[2], 
        graphX[2], graphY[2], "og",
        graphX[3], graphY[3], 
        graphX[3], graphY[3], "ob")
xmin, xmax, ymin, ymax = -150, 150, 0, 100
plt.axis([xmin, xmax, ymin, ymax])
plt.show()


