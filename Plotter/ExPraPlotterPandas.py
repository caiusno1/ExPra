import pandas as pd
import os
import glob
import matplotlib.pyplot as plt
testresults = [i for i in glob.glob('*.{}'.format("csv"))]
globaldflist=[]
for test in testresults:
    df=pd.read_csv(test,sep=" ",header=None)
    df=df.transpose()
    df=df[1:]
    df.columns= ["Soa","Correct","TimeVisible"]
    globaldflist.append(df)
globaldf=pd.concat(globaldflist)
print(globaldf)
for row in globaldf.values:
    if row[0]>0:
        row[1]=(row[1]+1)%2
frame=(globaldf.groupby(["Soa","TimeVisible" ]).sum()/globaldf.groupby(["Soa","TimeVisible"]).count()).rename(columns={'Correct':'Percentage'})
frame=frame.reset_index()
print(frame)
for tv in list(frame['TimeVisible'].unique()):
    currentgraph=frame.where(frame['TimeVisible']==tv).dropna(axis=0, how='any')
    plt.plot(currentgraph['Soa'],currentgraph['Percentage'],label="Experimental Var="+str(tv))
plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc=3,ncol=2, mode="expand", borderaxespad=0.)
plt.show()
