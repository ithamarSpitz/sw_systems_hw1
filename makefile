loops: basicClassification.c advancdClassifictionLoops.c
	gcc -o libclassloops.a basicClassification.c advancdClassifictionLoops.c 

recursives: basicClassification.c advancdClassifictionRecursion.c
	gcc -o libclassrec.a basicClassification.c advancdClassifictionRecursion.c

recursived: basicClassification.c advancdClassifictionRecursion.c
	gcc -shared  -o libclassrec.so basicClassification.c advancdClassifictionRecursion.c

loopd: basicClassification.c advancdClassifictionLoops.c
	gcc -shared -o libclassloops.so basicClassification.c advancdClassifictionLoops.c 

mains: main.c recursives
	[-f ./main ] && true || gcc -Wall main.c -l libclassrec.a

maindloop: main.c loopd
	[-f ./myfile ] && true || gcc -Wall main.c -l libclassloops.so

maindrec: main.c recursived
	[-f ./myfile ] && true || gcc -Wall main.c -l libclassloops.so

all: basicClassification.c advancdClassifictionLoops.c advancdClassifictionRecursion.c
	mains loops recursives recursived loopd

clean:
	rm *.a *.so