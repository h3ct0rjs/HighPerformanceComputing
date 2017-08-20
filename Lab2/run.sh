#!/usr/bin/env bash
#hfjimenez@utp.edu.co
#Preprocess the Txt Files, more easy manipulation in the C program
rm -rf clean* r.txt result.txt 
echo -e "[*]\x1B[0m Limpiando Archivos\n"
sed -e "s/,/ /g" datasets/data1500.txt>clean1.txt
sed -e "s/,/ /g" datasets/data2500.txt>clean2.txt
touch r.txt
echo -e "\x1B[33m[*]\x1B[0m Corriendo Programa"
gcc solve.c -w -s -o solver -fopenmp
./solver clean1.txt clean2.txt
echo -e "\x1B[33m[*]\x1B[0m Escribiendo Resultado a Stdout(result.txt)"
sed -e "s/ /,/g" r.txt>result.txt
rm r.txt clean1.txt clean2.txt solver 
echo -e "\x1B[32m[✔]TERMINADO\x1B[0m"
