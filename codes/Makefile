obj = main.o class.o func.o

my_hw: $(obj)
	g++ -o my_hw $(obj)
main.o: class.h func.h
func.o: class.h
.PHONY: clean
clean:
	-rm my_hw $(obj)
