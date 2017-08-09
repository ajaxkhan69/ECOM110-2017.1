APP = test

all: main.o
	$(CC) $^ -o $(APP)
	#echo $$(($(BUILD)+1)) > version.build
run: all
	./$(APP)
clean:
	rm $(APP)
