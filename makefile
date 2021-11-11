loops: basicClassification.c advancedClassificationLoop.c
	gcc -c basicClassification.c advancedClassificationLoop.c  -o libclassloops.a

recursives: basicClassification.c advancedClassificationRecursion.c
	gcc -c basicClassification.c advancedClassificationRecursion.c -o libclassrec.a

recursived: basicClassification.c advancedClassificationRecursion.c
	gcc -c -shared basicClassification.c advancedClassificationRecursion.c -o libclassrec.so

loopd: basicClassification.c advancedClassificationLoop.c
	gcc -c -shared basicClassification.c advancedClassificationLoop.c -o libclassloops.so

mains: main.c recursives
	[-f ./main ] && true || gcc -Wall main.c -l libclassrec.a

maindloop: main.c loopd
	[-f ./myfile ] && true || gcc -Wall main.c -l libclassloops.so

maindrec: main.c recursived
	[-f ./myfile ] && true || gcc -Wall main.c -l libclassloops.so

all: basicClassification.c advancedClassificationLoop.c advancedClassificationRecursion.c
	mains loops recursives recursived loopd

clean:
	rm *.a *.so