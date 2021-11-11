loops: basicClassification.c advancdClassifictionLoop.c
	gcc -c basicClassification.c advancdClassifictionLoop.c  -o libclassloops.a

recursives: basicClassification.c advancdClassifictionRecursion.c
	gcc -c basicClassification.c advancdClassifictionRecursion.c -o libclassrec.a

recursived: basicClassification.c advancdClassifictionRecursion.c
	gcc -c -shared basicClassification.c advancdClassifictionRecursion.c -o libclassrec.so

loopd: basicClassification.c advancdClassifictionLoop.c
	gcc -c -shared basicClassification.c advancdClassifictionLoop.c -o libclassloops.so

mains: main.c recursives
	[-f ./main ] && true || gcc -Wall main.c -l libclassrec.a

maindloop: main.c loopd
	[-f ./myfile ] && true || gcc -Wall main.c -l libclassloops.so

maindrec: main.c recursived
	[-f ./myfile ] && true || gcc -Wall main.c -l libclassloops.so

all: basicClassification.c advancdClassifictionLoop.c advancdClassifictionRecursion.c
	mains loops recursives recursived loopd

clean:
	rm *.a *.so