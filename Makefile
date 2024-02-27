CFLAGS = -std=c11 -Wall -Werror -Wextra
CPARSER = UnitTests/parser.c
LIBPARSER = parser.a
CAFINS = UnitTests/afin.c
LIBAFINS = afin.a
DOC_DIR = doc
DOC_FILE = doc.texi
CLANG_FORMAT_PATH = ../materials/linters/.clang-format
CHECKFLAGS = $(shell pkg-config --cflags --libs check)
TEST_PATH = s21_test
REPORT_PATH = s21_report

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
LEAK_CMD = CK_FORK=no leaks -atExit -- ./$(TEST_PATH)
DVI_CMD = makeinfo --html $(DOC_DIR)/$(DOC_FILE); open $(DOC_DIR)_html/index.html
endif
ifeq ($(UNAME), Linux)
LEAK_CMD = CK_FORK=no valgrind --leak-check=full ./$(TEST_PATH)
DVI_CMD = makeinfo --html $(DOC_DIR)/$(DOC_FILE) ; open $(DOC_DIR)/index.html
endif

.PHONY: all
all: clean $(LIBPARSER) $(LIBAFINS)

.PHONY: tests-build
tests-build: clean $(LIBPARSER) $(LIBAFINS)
	gcc $(CFLAGS) UnitTests/unit_tests.c $(LIBPARSER) $(LIBAFINS) -o $(TEST_PATH) $(CHECKFLAGS)

.PHONY: tests
tests: tests-build
	./s21_test

.PHONY: gcov_report
gcov_report: clean
	gcc $(CFLAGS) -fprofile-arcs -ftest-coverage UnitTests/unit_tests.c $(CPARSER) $(CAFINS) -o $(TEST_PATH) $(CHECKFLAGS)
	./$(TEST_PATH)
	rm -rf *unit_tests.g*
	lcov -d ./ --capture --output-file s21_test.info
	genhtml s21_test.info --output-directory $(REPORT_PATH)
	open $(REPORT_PATH)/index.html

$(LIBPARSER):
	gcc $(CFLAGS) -c $(CPARSER)  
	ar -src $(LIBPARSER) *.o
	rm *.o
	ranlib $(LIBPARSER)

$(LIBAFINS):
	gcc $(CFLAGS) -c $(CAFINS)
	ar -src $(LIBAFINS) *.o
	rm *.o
	ranlib $(LIBAFINS)

.PHONY: dvi
dvi:
	$(DVI_CMD)
	
.PHONY: install
install: clean
	sudo rm -rf /opt/3DViewer/bin/3DViewer
	cd 3DViewer; qmake; sudo make install
	cd .. ; ./build/3DViewer

.PHONY: uninstall
uninstall: clean
	sudo rm -rf ../build/* ../build/obj/*

.PHONY: dist
dist: 
	tar cfvz 3DViewer.tar.gz 3DViewer

.PHONY: style-test
style-test:
	clang-format -n \
	3DViewer/source/*.c 3DViewer/source/*.h \
	UnitTests/*.c UnitTests/*.h \
	3DViewer/*.h 3DViewer/*.cpp -style=file:$(CLANG_FORMAT_PATH);

.PHONY: style-edit
style-edit:
	clang-format -i \
	3DViewer/source/*.c 3DViewer/source/*.h \
	UnitTests/*.c UnitTests/*.h \
	3DViewer/*.h 3DViewer/*.cpp -style=file:$(CLANG_FORMAT_PATH);

.PHONY: leaks
leaks: tests-build
	$(LEAK_CMD)

.PHONY: cppcheck
cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem 3DViewer/source/*.c 3DViewer/source/*.h 3DViewer/*.h 3DViewer/*.cpp

.PHONY: clean
clean:
	rm -rf *.o 3DViewer/*.o
	rm -rf *.a 3DViewer/*.a
	rm -rf $(TEST_PATH)
	rm -rf main.exe 3DViewer/3DViewer
	rm -rf 3DViewer/.qmake.stash
	rm -rf *.gcno *.gcda *.info
	rm -rf $(REPORT_PATH)
	rm -rf *.stash
	rm -rf 3DViewer/moc_*
	rm -rf 3DViewer/Makefile
	rm -rf 3DViewer.tar.gz
	rm -rf $(DOC_DIR)/index.html
