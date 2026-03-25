CC=g++
CPPFLAGS=-I/mingw64/include -std=c++17 -Wall
LIBFLAGS=-L/mingw64/lib -lsfml-graphics -lsfml-window -lsfml-system
EXEC=evolution

CPPDIR=src
HPPDIR=lib
OBJDIR=obj
SRCFILES := $(shell find $(CPPDIR) -type f -name "*.cpp")
DECFILES := $(shell find $(HPPDIR) -type f -name "*.hpp")
OBJFILES := $(patsubst $(CPPDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCFILES))
ALLFILES := $(SRCFILES) $(DECFILES)

.PHONY: all

all: $(EXEC)

$(EXEC): $(OBJFILES)
	@mkdir -p $(OBJDIR)
	$(CC) $(CPPFLAGS) $^ -o $@ $(LIBFLAGS)

$(OBJDIR)/%.o: $(CPPDIR)/%.cpp $(DECFILES)
	@mkdir -p $(@D)
	$(CC) -c $(CPPFLAGS) $< -o $@

.PHONY: format fmt check-format

format fmt:
	clang-format -i $(ALLFILES)

check-format:
	clang-format --dry-run --Werror $(ALLFILES)

.PHONY: clean

clean:
	rm -rf $(OBJDIR) $(EXEC)