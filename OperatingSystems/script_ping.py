import subprocess

ip = "10.0.0."
last = 255

def doStuff():
	lista = []
	for i in range(2,last):
		proc = subprocess.Popen(["ping "+ ip + str(i)+" -c 1 -i 1"], stdout=subprocess.PIPE, shell=True)
		(out, err) = proc.communicate()
		out = out.split(" ")
		j = 0
		for i in out:
			j = j+1
			if i == "PING": 
				break
		k = 0
		for i in out:			
			k = k+1
			if i == "transmitted,": 
				break
		lista.append([out[k],out[j]])
	return lista
lista = doStuff()

succes = []
failure = []
for i in lista:
	print i[1]
	if i[0] != '0':
		succes.append(i[1])
	else:
		failure.append(i[1])
for i in succes:
	print i
print "fallos"
for i in failure:
	print i



