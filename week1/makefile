.PHONY: clean

bin/ut_shape: ut_shape.cpp circle.h rectangle.h triangle.h
	g++ ut_shape.cpp -o bin/ut_shape -lgtest -lpthread

clean:
	rm bin/ut_shape
