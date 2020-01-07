CC=gcc 
AR=ar
MAINOBJECTS2=frequency_r_main.o
MAINOBJECTS1=frequency_main.o
LIBOBJECTS=frequency.o trie.h 
LIBOBJECTS2=frequency_r.o trie.h
LIBa=libfrequency_.a 
LIBa2=libfrequency_r_.a
LIBso=libfrequency.so 
LIBso2=libfrequency_r.so
FLAGS= -Wall -g 

all: frequencyd frequencys frequency_rd frequency_rs frequency frequency_maind  frequency_r frequency_r_maind

frequency: $(MAINOBJECTS1) $(LIBa)
	$(CC) $(flags) -o frequency $(MAINOBJECTS1) $(LIBa) 
frequency_maind: $(MAINOBJECTS1)
	$(CC) $(flags) -o frequency_maind $(MAINOBJECTS1) ./$(LIBso)
frequency_r: $(MAINOBJECTS2) $(LIBa2)
	$(CC) $(flags) -o frequency_r $(MAINOBJECTS2) $(LIBa2) 
frequency_r_maind: $(MAINOBJECTS2)
	$(CC) $(flags) -o frequency_r_maind $(MAINOBJECTS2) ./$(LIBso2)

frequencyd: $(LIBOBJECTS)
	$(CC) -shared -o $(LIBso) $(LIBOBJECTS)
frequencys: $(LIBOBJECTS)
	$(AR) -rcs $(LIBa) $(LIBOBJECTS)
frequency_rd: $(LIBOBJECTS2)
	$(CC) -shared -o $(LIBso2) $(LIBOBJECTS2)
frequency_rs: $(LIBOBJECTS2)
	$(AR) -rcs $(LIBa2) $(LIBOBJECTS2)

frequency_main.o: frequency_main.c trie.h 
	$(CC) $(FLAGS) -c frequency_main.c
frequency_r_main.o: frequency_r_main.c trie.h
	$(CC) $(FLAGS) -c frequency_r_main.c
frequency.o: frequency.c
	$(CC) -fPIC $(FLAGS) -c frequency.c
frequency_r.o: frequency_r.c
	$(CC) -fPIC $(FLAGS) -c frequency_r.c

.PHONY: clean all frequencyd frequencys frequency_rd frequency_rs

clean: 
	rm -f *.o frequency_mains frequency_maind frequency_r_mains frequency_r_maind $(LIBso) $(LIBa) $(LIBso2) $(LIBa2)
