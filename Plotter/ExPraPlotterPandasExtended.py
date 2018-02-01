import pandas as pd
import os
import sys
import glob
import matplotlib.pyplot as plt
testresults = [i for i in glob.glob('*.{}'.format("csv"))]
globaldflist=[]
index=0

outputnameTOJ="std-toj-block-SphereInBox.csv"
resultdir="images"
if not os.path.exists(resultdir):
    os.makedirs(resultdir)
if os.path.exists(outputnameTOJ):
	os.remove(outputnameTOJ)

for test in testresults:
    df=pd.read_csv(test,sep=" ",header=None)
    df=df.transpose()
    df=df[1:]
    df.columns= ["Soa","Correct","TimeVisible"]
    globaldflist.append(df)
globaldflist.append(pd.concat(globaldflist))
compresult=pd.concat(globaldflist)
testresults.append("complete.all")
for df in globaldflist:
    name_parts=testresults[index].split('.')
    id = name_parts[0]
    outputnamepng = id + '.png'
    for row in df.values:
        if row[0]>0:
            row[1]=(row[1]+1)%2
    frame=(df.groupby(["Soa","TimeVisible" ]).sum()/df.groupby(["Soa","TimeVisible"]).count()).rename(columns={'Correct':'Percentage'})
    frame=frame.reset_index()
    print(frame)
    plt.xlabel('SOA (ms)')
    plt.ylabel('p("probe first")')
    for tv in list(frame['TimeVisible'].unique()):
        currentgraph=frame.where(frame['TimeVisible']==tv).dropna(axis=0, how='any')
        plt.plot(currentgraph['Soa'],currentgraph['Percentage'],label="Experimental Var="+str(tv))
    plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc=3,ncol=2, mode="expand", borderaxespad=0.)
    plt.savefig(resultdir+"\\"+outputnamepng)
    plt.clf()
    index=index+1
df=compresult
df=df.rename(columns={'Soa':'SOA'})
df=df.rename(columns={'TimeVisible':'Condition'})
df = df.groupby(['Condition', 'SOA'])
df = df['Correct'].agg({'Repetitions': 'count','Count': 'sum'})
df['Relative'] = df['Count']/ df['Repetitions']
df.to_csv(outputnameTOJ)

