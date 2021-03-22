
TARGET_LIST=release

FILE-release=prog

COMPILER-release=g++
COMPILATION_FLAGS-release=-O3 -Wall -Wextra -pedantic -Wno-unused-result -g
LINKER_FLAGS-release=

MAINFILE-release=main
 SRCPATH-release=./src/
 INCPATH-release=./include/
 OBJPATH-release=./objects/Release/

SOURCE_EXT-release=.cpp
HEADER_EXT-release=.h


FIRST_TARGET=$(firstword $(TARGET_LIST))

.DEFAULT_GOAL:=$(FIRST_TARGET)

FILE=

FILE-SOURCE=$(wildcard $(SRCPATH-$(FILE))*$(SOURCE_EXT-$(FILE)))
HEADERS=$(wildcard $(INCPATH-$(FILE))*$(HEADER_EXT-$(FILE)))
OBJECTS=$(subst $(SOURCE_EXT-$(FILE)),.o,$(subst $(SRCPATH-$(FILE)),$(OBJPATH-$(FILE)),$(FILE-SOURCE)))

OBJCOUNT=$$(($(words $(OBJECTS))+1))
CURCOUNT=1


all: objdir
	@ $(foreach F,$(TARGET_LIST), $(MAKE) --silent --stop $(F);)

%:
	@ $(eval FILE=$@)
	@ if [ "$(findstring $(FILE),$(TARGET_LIST))" = "$(FILE)" ]; then ($(MAKE) --silent --stop FILE=$(FILE) objdir $(FILE-$(FILE));printf "[100%%] Built target %s\n" $(FILE);); else (echo "make: There is no recipe for target '$(FILE)'"; exit); fi

$(FILE-$(FILE)): $(OBJECTS)
	@ printf "[%3i%%]" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ echo " \e[92mLinking executable $(FILE-$(FILE))\e[0m"
	@ $(COMPILER-$(FILE)) $^ $(COMPILATION_FLAGS-$(FILE)) $(LINKER_FLAGS-$(FILE)) -o $(FILE-$(FILE)) $(foreach I,$(INCPATH-$(FILE)),$(shell echo -I$(I)))

$(OBJPATH-$(FILE))%.o: $(SRCPATH-$(FILE))%$(SOURCE_EXT-$(FILE)) $(HEADERS)
	@ printf "[%3i%%]" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ echo " \e[32mBuilding $(COMPILER-$(FILE)) object $@\e[0m"
	@ $(COMPILER-$(FILE)) $< -c $(COMPILATION_FLAGS-$(FILE)) -o $@ $(foreach I,$(INCPATH-$(FILE)),$(shell echo -I$(I)))
	@ $(eval CURCOUNT=$(shell echo $$(($(CURCOUNT)+1))))

$(OBJPATH-$(FILE))$(MAINFILE-$(FILE)).o: $(SRCPATH-$(FILE))$(MAINFILE-$(FILE))$(SOURCE_EXT-$(FILE)) $(HEADERS)
	@ printf "[%3i%%]" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ echo " \e[32mBuilding $(COMPILER-$(FILE)) object $@\e[0m"
	@ $(COMPILER-$(FILE)) $< -c $(COMPILATION_FLAGS-$(FILE)) -o $@ $(foreach I,$(INCPATH-$(FILE)),$(shell echo -I$(I)))
	@ $(eval CURCOUNT=$(shell echo $$(($(CURCOUNT)+1))))

objdir:
	@ $(foreach F,$(TARGET_LIST), $(shell mkdir -p $(OBJPATH-$(F))))

clean:
	@ $(foreach F,$(TARGET_LIST), $(shell rm -rf $(OBJPATH-$(F))*.o $(FILE-$(F)) *~))
	@ echo "All binaries have been deleted."

.PHONY: all clean