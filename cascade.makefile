# Makefile for cascade

cascade.exe: cascade.driver.o  
	g++ -o cascade.exe cascade.driver.o

cascade.driver.o: cascade.driver.cpp cascade.node.h
	g++ -Wall -c cascade.driver.cpp
