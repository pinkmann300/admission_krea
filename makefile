CC = g++ 

CFLAGS = -Wall -g

main.exe: main.o admission_krea.o applicant.o admission.o 
    $(CC) $(CFLAGS) -o main.exe main.o admission_krea.o applicant.o admission.o 

main.o: main.cpp admission_krea.cpp applicant.h admission.h
    $(CC) $(CFLAGS) -c main.cpp 

admission_krea.o: admission_krea.cpp applicant.h admission.h 
    $(CC) $(CFLAGS) -c admission_krea.cpp

applicant.o: applicant.h

admission.o: admission.h