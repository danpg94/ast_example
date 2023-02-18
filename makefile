

%.o: %.cpp
		g++ -o $@ -c $<

test: main.o base.o
		g++ -o $@ $^