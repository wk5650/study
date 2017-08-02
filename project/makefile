TARGET:=main
BOJECTS:=main.o menu.o teacher.o teacher_subject.o student.o
CC:=gcc
OPTIONS:=-Wall

$(TARGET):$(OBJECTS)
	$(CC) $^ -o $@ $(OPTIONS)
%.o:%.c
	$(CC) -c $< -o $@ $(OPTIONS)
clean:
	rm -rvf *.o $(TARGET)
