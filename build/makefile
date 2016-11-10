SRC_PATH=../src
LIB_PATH=../lib
OUT_PATH=../
SOURCES=main.cpp CrtArvoreB.cpp ArvoreB.cpp No.cpp RegVariavel.cpp RegFixo.cpp utils.cpp

LIST_SOURCES=$(addprefix $(SRC_PATH)/,$(SOURCES))

CC=g++
CFLAGS=-g -ansi -Wall -std=c++0x

all:
	mkdir -p $(OUT_PATH)
	$(CC) ${CFLAGS} -I${LIB_PATH} ${LIST_SOURCES} -o $(OUT_PATH)main
