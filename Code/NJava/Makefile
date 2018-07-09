JNIINCLUDE=/usr/lib/jvm/java-8-openjdk-amd64/include
JNILINUXINCLUDE = /usr/lib/jvm/java-8-openjdk-amd64/include/linux
OUTDIR = ./out/
App_main:App_main.o
	g++ $(OUTDIR)App_main.o -o $(OUTDIR)App_main
App_main.o:App_main.cpp
	g++ -c App_main.cpp -I$(JNIINCLUDE) -I$(JNILINUXINCLUDE) -o $(OUTDIR)App_main.o -g

clean:
	rm $(OUTDIR)App_main $(OUTDIR)*.o -f
