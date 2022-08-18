import os

#输入更改文件名称的目录
os.chdir(r"D:\Work\other\general_Plugin\General_ExcelEditor")
#需要修改的旧名称
oldName = "A52ResistanceEvaluate"
#输入文件新名称
newName = "ExcelEditor"

#循环修改名称
for root,dirs,files in os.walk(os.getcwd()):
    for filename in files:
        if oldName in filename:
            fullfilename=os.path.join(root, filename)
            newFileName = os.path.dirname(fullfilename) + "\\" + filename.replace(oldName,newName)
            os.rename(fullfilename, newFileName)

