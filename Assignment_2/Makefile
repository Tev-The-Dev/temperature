Temperature: temperature.o driver.o
	g++ -o Temperature temperature.o driver.o

temperature.o: temperature.cpp temperature.h
	g++ -c temperature.cpp temperature.h

driver.o: driver.cpp temperature.h
	g++ -c driver.cpp temperature.h

clean:
	 rm  *.o Temperature
