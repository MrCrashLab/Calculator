CC=gcc
CFLAGS= -Wall -Werror -Wextra -c
SOURCE=smart_calc_src/s21_*/*.c
TEST_SOURCE=smart_calc_src/test/*.c
GUI_SOURCE=smart_calc_gui/*.cpp
COMPILE_SOURCE=smart_calc-1.0

all: clean install test gcov_report open_report dvi open_dvi

s21_smartcalc.a:
	$(CC) $(CFLAGS) $(SOURCE)
	ar rc s21_smartcalc.a *.o
	ranlib s21_smartcalc.a
	$(MAKE) clean_without_a

install: s21_smartcalc.a
	mkdir $(COMPILE_SOURCE)
	cd $(COMPILE_SOURCE) && cmake -DCMAKE_BUILD_TYPE=Release ../smart_calc_gui && cmake --build .
	cd $(COMPILE_SOURCE) && rm -rf CMakeFiles *.txt *.cmake Makefile .qt *_autogen
	# rm s21_smartcalc.a

uninstall:
	rm -rf $(COMPILE_SOURCE)

dist:
	tar -czvf $(COMPILE_SOURCE).tar $(COMPILE_SOURCE) 

dvi: 
	texi2dvi docs.tex

open_dvi:
	open docs.dvi


test: s21_smartcalc.a
	$(CC) s21_smartcalc.a $(TEST_SOURCE) -lcheck -o test.out
	./test.out
	-rm test.out
	$(MAKE) clean

clean_without_a:
	-rm *.o
	-rm *.out
	-rm *.gcda
	-rm *.gcno
	-rm -rf report
	-rm *.info
	-rm *.aux
	-rm *.dvi
	-rm *.pdf
	-rm *.log
	-rm -rf $(COMPILE_SOURCE)

clean: clean_without_a
	-rm *.a

gcov_report:
	gcc --coverage $(TEST_SOURCE) $(SOURCE) -o test.out -lcheck
	-./test.out
	lcov -t "test.out" -o test.info -c -d .
	genhtml -o report test.info


open_report: gcov_report
	open report/index.html

style:
	clang-format -n $(SOURCE) $(TEST_SOURCE) $(GUI_SOURCE) -style=google
	clang-format -i $(SOURCE) $(TEST_SOURCE) $(GUI_SOURCE) -style=google
