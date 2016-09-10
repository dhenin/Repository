#! /bin/sh 

# Construit le premier tableau au moyen du programme en python 

for i in 0 1 2 3 4 
do 
	for j in 0 1 2 
	do 
		python Ackerman.py $j $i 
	done 
	echo  # On saute une ligne 
done 
