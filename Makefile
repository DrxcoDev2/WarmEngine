# === Start Makefile from engine ===

# === Compiler and Flags ===
CC      = g++
CFLAGS  = -Wall -Wextra -std=c++17
CFG     = ./config/
INCLUDE = -I$(CFG)
SDL     = $(shell sdl2-config --cflags --libs)

# === Targets ===
TARGET  = build/main
SRC     = main.cpp $(CFG)config.cpp
HEADERS = $(CFG)config.h warm.h

# === Default build ===
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(SRC) $(HEADERS)
	@mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(INCLUDE) $(SDL)

# === Clean compiled files ===
clean:
	rm -f $(TARGET)

# === Run executable ===
run: $(TARGET)
	./$(TARGET)
