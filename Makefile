run:
	rm -rf build
	mkdir build
	cp -r data build/
	cp -r resources build/
	(cd build/ && cmake ../)
	(cd build/ && make)
	(cd build/ && ./wilson)