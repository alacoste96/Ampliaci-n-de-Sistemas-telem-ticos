# *****************************************************
# Julio Vega
# Example of Makefile
# *****************************************************
# NOTES: it uses '>' as prefix of my recipes (.RECIPEPREFIX is set in line 11)
# since all actions of every Makefile's rule are identified by tabs and I do not
# use tabs in my file editor. Otherwise, I will get the 'missing separator' error.
#
# To check whether a tab character is used, run: cat -e -t -v Makefile
# It shows the presence of tabs (-t) with ^I and line endings (-e) with $
# *****************************************************

# Makefile

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -g -Wall -Wshadow

# Directorios de código fuente y de inclusión
SRCDIR = src
INCDIR = include

# Archivos fuente y objeto
SOURCES := $(wildcard $(SRCDIR)/*.cpp) main.cpp
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=%.o)

# Nombre del ejecutable
EXECUTABLE = main

# Reglas de compilación
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Regla de compilación para main.cpp
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm *.o main
