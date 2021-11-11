loops: basicClassification.c advancedClassifictionLoop.c
	gcc -c basicClassification.c advancedClassifictionLoop.c  -o libclassloops.a

recursives: basicClassification.c advancedClassifictionRecursion.c
	gcc -c basicClassification.c advancedClassifictionRecursion.c -o libclassrec.a

recursived: basicClassification.c advancedClassifictionRecursion.c
	gcc -c -shared basicClassification.c advancedClassifictionRecursion.c -o libclassrec.so

loopd: basicClassification.c advancedClassifictionLoop.c
	gcc -c -shared basicClassification.c advancedClassifictionLoop.c -o libclassloops.so

mains: main.c recursives
	[-f ./main ] && true || gcc -Wall main.c -l libclassrec.a

maindloop: main.c loopd
	[-f ./myfile ] && true || gcc -Wall main.c -l libclassloops.so

maindrec: main.c recursived
	[-f ./myfile ] && true || gcc -Wall main.c -l libclassloops.so

all: basicClassification.c advancedClassifictionLoop.c advancedClassifictionRecursion.c
	mains loops recursives recursived loopd

clean:
	rm *.a *.so