import os
import shutil

dirs=os.listdir()

for dir in dirs:
    if(os.path.isdir(dir)):
        myf=dir+"/"+"solution.cpp"
        if os.path.isfile(myf):
            shutil.move(myf,dir+".cpp")

for dir in dirs:
    if(os.path.isdir(dir)):
        if(len(os.listdir(dir))==0):
            os.removedirs(dir)