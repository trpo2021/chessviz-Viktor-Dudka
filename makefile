<<<<<<< HEAD
all: chess2.exe
chess2.exe: chess2.cpp
	g++ -o chess2.exe chess2.cpp
||||||| ac87695


all: chessviz-Viktor-Dudka

chessviz-Viktor-Dudka:main.o foo.o 
 gcc main.o foo.o -o chessviz-Viktor-Dudka.exe

main.o:chesslab1.cpp
 gcc -c chesslab1.cpp
foo.o:foo.c
 gcc -c foo.c
clean: 
 rm -rf *.o*.exe 
=======
APP_NAME = chessviz
LIB_NAME = libchessviz
CC = g++

CPPFLAGS = -Wall -Wextra -Werror -I src -MP -MMD
LDFLAGS =
LDLIBS = -lm

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

SRC_EXT = cpp

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

.PHONY: all
all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/$(SRC_DIR)/$(APP_NAME)/%.o: $(SRC_DIR)/$(APP_NAME)/%.cpp
	$(CC) -c $(CPPFLAGS) $< -o $@ $(LDLIBS)

$(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/%.o: $(SRC_DIR)/$(LIB_NAME)/%.cpp
	$(CC) -c $(CPPFLAGS) $< -o $@ $(LDLIBS)

.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
>>>>>>> lab3
