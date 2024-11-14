NAME	= MatrixGTest

Google_Test	= googletest/build/lib/libgtest.a
REPO_DIR	= googletest

.PHONY: all
all: $(NAME)

$(REPO_DIR):
	git clone https://github.com/google/googletest.git

$(Google_Test): $(REPO_DIR)
	cd googletest ;\
	mkdir build ;\
	cd build ;\
	cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ .. ;\
	make

$(NAME): $(Google_Test)

.PHONY: clean
clean:
	rm -rf googletest

.PHONY: re
re: clean all