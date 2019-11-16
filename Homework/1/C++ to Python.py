import random
import os
os.system("cls") #safhe namayesh ra pak mikonad#
possiblekeys = ["mushroom", "pineapple", "neighborhood", "citizen","programming", "darkness", "fundamental", "encyclopedia","businessman", "restaurant", "observatory", "civilization"]
a = random.randint(0,len(possiblekeys))
answer = possiblekeys[a]   #adadi manande n ra entekhab mikonad ve n omin ozve list bala ra entekhab mikonad#
lsa1 = list(answer)     #liste horufe javab hast
lsa2 = []
#listi ast k hads haye karbar ra zakhire mikonad.b tore pish farz "-" baraye har harf gharar darad ta zamani k karbar an harf ra hads bezanad#
for i in range(len(answer)):
	lsa2.append("-")
print ("\n")
print ("\n")
def shower(list):
	a = ""
	for i in range(len(list)):
		a = a + list[i]
	print (a)
	return 0
#tabe shower tamae ozvhaye darune lsa2 ra b ham michasbanad v print mikonad
while lsa1 != lsa2:
	shower(lsa2)
	hads = raw_input("Guess a letter  :")
	if hads in lsa1:                  #agar hadse karbar dar javab bud an ra namayesh midahad
		tedadeHarf = lsa1.count(hads)
		for j in range(tedadeHarf):   #in halghe baraye in ast k agar yek bish az ye bar bashad an ra ezafe konad
			lsa2[(lsa1.index(hads))+j]=hads
			lsa1.remove(hads)
	elif hads == answer:         #agar karbar javab ra kamel benevisad bazi tamam mishavad!
		break
	else:
		print("your letter isn't in the word !! ")
	lsa1=list(answer)

print ("\n")
print ("answer was "+answer+" !!")
print ("Game Over")
while True:
	print('\n')
	if (raw_input("press any key to exit :"))==0:break
	else:break
#in halghe faghat va faghat baraye in hast k b karbar ejaze dahad ta khodash az barname kharej beshavad
exit
