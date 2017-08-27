import subprocess
import os

name_folder = "Folder_Script"
username = "secret_agent"
extensions = ["cpp","pdf","img","py"]

def getCurrentPath():	
	aux = ""
	proc = subprocess.Popen(["pwd"], stdout=subprocess.PIPE, shell=True)
	(out, err) = proc.communicate()
	for i in range(0,len(out)):
		if out[i] != '\n':
			aux = aux + out[i]
	return aux

def getFolderList(path):
	os.chdir(path)
	proc = subprocess.Popen(["ls -d */"], stdout=subprocess.PIPE, shell=True) 
	os.system("clear")
	(out,err) = proc.communicate()

	err = str(err)
	
	out = out.split("\n")
	out.pop()
	return out

def copyFiles(path):
	
	os.chdir(path)
	command = "ls | egrep '"
	for i in extensions:
		command = command + "\."+i+"$|"
	auxcommand = ""
	for i in range(0,len(command)-1):
		auxcommand = auxcommand + command[i]
	auxcommand = auxcommand + "'"
	command = auxcommand

	proc = subprocess.Popen([command], stdout=subprocess.PIPE, shell=True) 
	(out,err) = proc.communicate()

	out = out.split('\n')
	out.pop()

	for j in out:
		os.system("cp " + j +" " + "/home/" + username + "/Escritorio/" + name_folder)

def visit(lista,path):
	if len(lista) <= 0:
		return
	if len(path) < 17: return

	copyFiles(path)
	for i in lista:
		aux = ""
		for k in range (0,len(i)-1):
			aux = aux + str(i[k])
		newpath = path + "/" + aux
		newlist = getFolderList(newpath)
		visit(newlist,newpath)
def main():
	os.system("rm -r " + name_folder)
	os.system("mkdir " + name_folder)

	path = getCurrentPath()
	
	visit(getFolderList(path),path)
main()
os.chdir("/home/" + username + "/Escritorio/")
print("comprimiendo...")
proc = subprocess.Popen(["tar zcfp " + name_folder + ".tgz "  + name_folder], stdout=subprocess.PIPE, shell=True)
proc.communicate()
print "completado"
	