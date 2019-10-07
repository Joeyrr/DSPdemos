CXX=g++
Objects=fftTest.o fft.o
fft:$(Objects)
	$(CXX) -o fft $(Objects)
fftTest.o:fftTest.cpp fft.h
	$(CXX) -c fftTest.cpp
fft.o:fft.cpp fft.h
	$(CXX) -c fft.cpp

