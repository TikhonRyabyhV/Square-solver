OBJECTS=	main.o square_solver.o in_output.o help_functions.o
TESTOBJECTS=	unit_test.o square_solver.o one_test_cycle.o file_input.o data_list.o help_functions.o

.cpp.o:
	@ g++ -c -o $@ $<
out: $(OBJECTS)
	@ g++ -o out $(OBJECTS)
	@ rm -f *.o
	@ echo "Success"
test_out: $(TESTOBJECTS)
	@ g++ -o test_out $(TESTOBJECTS)
	@ rm -f *.o
	@ echo "Success"
.SUFFIXES: .cpp.o
