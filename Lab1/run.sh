#!/usr/bin/env bash
#hfjimenez@utp.edu.co
#Preprocess the Txt Files, more easy manipulation in the C program
echo -e "[*]\x1B[0m Limpiando Archivos\n"
sed -e "s/,/ /g" data1.txt>clean1.txt
sed -e "s/,/ /g" data2.txt>clean2.txt
touch r.txt
echo -e "\x1B[33m[*]\x1B[0m Corriendo Programa"
gcc solve.c -w -s -o solver 
./solver clean1.txt clean2.txt
echo -e "\x1B[33m[*]\x1B[0m Escribiendo Resultado a Stdout(result.txt)"
sed -e "s/ /,/g" r.txt>result.txt
rm r.txt clean1.txt clean2.txt
echo -e "\x1B[32m[✔]TERMINADO\x1B[0m"
