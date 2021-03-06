all: ques4send ques4receive

ques4send: ques4send.c 
	gcc -o ques4send.out ques4send.c -lrt
	
ques4receive: ques4receive.c 
	gcc -o ques4receive.out ques4receive.c -lrt
	
runques4receive:
	./ques4receive.out

runsol4send:
	./ques4send.out

clean:
	rm -rf *.out *.o
