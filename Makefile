SHELL := cmd.exe
.SHELLFLAGS := /C

PROJECT := digital_clock
TARGET := $(PROJECT).exe
DEBUG_TARGET := $(PROJECT)_debug.exe
SRC := digital_clock.cpp

RAYLIB_BIN := C:/msys64/ucrt64/bin
CXX := $(RAYLIB_BIN)/g++.exe
PKG_CONFIG := $(RAYLIB_BIN)/pkg-config.exe

COMMON_CXXFLAGS := -std=c++20 -Wall -Wextra -pedantic $(shell "$(PKG_CONFIG)" --cflags raylib)
DEBUG_CXXFLAGS := $(COMMON_CXXFLAGS) -g -O0
LDLIBS := $(shell "$(PKG_CONFIG)" --libs raylib)
RUN_ENV := set PATH=$(RAYLIB_BIN);%PATH% &&

.PHONY: all debug run clean

all: $(TARGET)

$(TARGET): $(SRC)
	"$(CXX)" $(COMMON_CXXFLAGS) $< -o $@ $(LDLIBS)

$(DEBUG_TARGET): $(SRC)
	"$(CXX)" $(DEBUG_CXXFLAGS) $< -o $@ $(LDLIBS)

debug: $(DEBUG_TARGET)

run: $(TARGET)
	$(RUN_ENV) "$(TARGET)"

clean:
	if exist "$(TARGET)" del /Q "$(TARGET)"
	if exist "$(DEBUG_TARGET)" del /Q "$(DEBUG_TARGET)"
	if exist "build" rmdir /S /Q "build"
