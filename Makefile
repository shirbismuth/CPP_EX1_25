CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17

# קבצי מקור
SRC = main.cpp graph.cpp algorithms.cpp queue.cpp min_heap.cpp union_find.cpp
# קובץ טסטים
TEST_SRC = test_all.cpp  # שמות קבצי טסטים

# קובץ הפלט של התוכנית הראשית
EXE = bin/Main
# קובץ הפלט של הטסטים
TEST_EXE = bin/test

# יעד ברירת מחדל (קובץ תוכנית ראשי)
all: Main

# יצירת התוכנית הראשית
Main: $(SRC)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXE)

# הרצה רגילה של התוכנית הראשית
run: Main
	./$(EXE)

# הרצה עם valgrind לבדוק זליגת זיכרון בתוכנית הראשית
valgrind: Main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXE)

# הרצת הטסטים
test: $(TEST_EXE)
	./$(TEST_EXE)

# יצירת קובץ טסטים מאוחד והרצתם
$(TEST_EXE): $(TEST_SRC) graph.cpp algorithms.cpp queue.cpp min_heap.cpp union_find.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(TEST_SRC) graph.cpp algorithms.cpp queue.cpp min_heap.cpp union_find.cpp -o $(TEST_EXE)

# ניקוי קבצים זמניים
clean:
	rm -rf bin *.o *.out *.exe

# הרצה עם valgrind לבדיקת זיכרון בטסטים
valgrind-tests: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_EXE)
