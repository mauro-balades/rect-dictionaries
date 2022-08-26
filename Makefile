CXX = clang++
OPT = opt
LLINK = llvm-link
LLDIS = llvm-dis

SOURCEDIR := ./src
SOURCES := $(wildcard $(SOURCEDIR)/*.cc)
OBJDIR=./obj
LIBS = ""  #your external libraries
CXXFLAGS = -emit-llvm #your flags
OBJECTS := $(patsubst $(SOURCEDIR)/%.cc,$(OBJDIR)/%.bc, $(SOURCES))
DEPENDS := $(patsubst $(SOURCEDIR)/%.cc,$(OBJDIR)/%.d, $(SOURCES))

# ADD MORE WARNINGS!
WARNING := -Wall -Wextra

# .PHONY means these rules get executed even if
# files of those names exist.
.PHONY: all clean

# The first rule is the default, ie. "make",
# "make all" and "make parking" mean the same
all: ruptime

clean:
	$(RM) $(OBJECTS) $(DEPENDS) ruptime

# Linking the executable from the object files
# $^   # "src.c src.h" (all prerequisites)
ruptime: $(OBJECTS)
	$(LLINK) $^ > $(OBJDIR)/export_lib.bc
	$(LLDIS) $(OBJDIR)/export_lib.bc > $(OBJDIR)/export_lib.ll

-include $(DEPENDS)

$(OBJDIR):
	mkdir -p $(OBJDIR)
#Note the dependency from the folder $(OBJDIR) and the
#rule above to generate it. However with the symbol |
# no ricompilation is perform if the folder if it modified
$(OBJDIR)/%.bc: $(SOURCEDIR)/%.cc Makefile | $(OBJDIR)
	$(CXX) $(WARNING) -emit-llvm -MMD -MP -c -S $< -o $@
