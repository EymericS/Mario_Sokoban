SDL_DIR = extern/SDL2
SDL_DLL = $(SDL_DIR)/bin
ifeq ($(OS), Windows_NT) # Détecte Windows comme OS pour W10, W8, W7, WXP, W_NT
	RM_FILE ?= del /f /s /q
	RM_DIR ?= rmdir /Q /S
	TOUCH ?= type nul >
	MK_DIR ?= mkdir
	COPY ?= copy
	SLASH ?= $\\
	SYS ?= Windows
	SDL_INC ?= $(SDL_DIR)/include
	SDL_LIB ?= $(SDL_DIR)/lib
else
	RM_FILE ?= rm -f
	RM_DIR ?= rm -rf
	TOUCH ?= touch
	MK_DIR ?= mkdir
	COPY ?= cp
	SLASH ?= /
	SYS ?= Unix
	SDL_INC ?= $(shell $(SDL_BIN)/sdl2-config --cflags)
	SDL_LIB ?= $(shell $(SDL_BIN)/sdl2-config --libs)
endif

CC = gcc # Compilateur utilisé
LD = gcc # Compilateur de lien utilisé
CFLAGS = -g -Wall -Wextra -pedantic -pedantic-errors -I$(SDL_INC)# $(shell sdl2-config --cflags) # Options pour le compilateur
LDFLAGS = -L$(SDL_LIB) -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf #-lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer #$(shell sdl2-config --libs) # Option pour le compilateur de lien
DEPFLAGS = -MM # Option pour la création des fichiers de dépendance

SRC_DIR = src
INC_DIR = $(SRC_DIR)/header
BIN_DIR = bin
OBJ_DIR = obj
BIN_DIR_SYS = $(BIN_DIR)/$(SYS)
OBJ_DIR_SYS = $(OBJ_DIR)/$(SYS)

APP = app
EXEC = $(BIN_DIR_SYS)/app 

conv = $(subst /,$(SLASH),$(1))


all: $(EXEC)

DEPS = $(OBJ_DIR_SYS)/main.o $(OBJ_DIR_SYS)/input.o $(OBJ_DIR_SYS)/menu.o $(OBJ_DIR_SYS)/fonction_SDL.o 
$(EXEC): $(DEPS) $(BIN_DIR_SYS)/.dirstamp
	@echo Linking of $(call conv,$(DEPS)) for $(call conv,$@) ...
	@$(LD) $(DEPS) -o $@ $(LDFLAGS)
	@echo Linking done !

$(OBJ_DIR_SYS)/main.o: $(INC_DIR)/constantes.h $(INC_DIR)/fonction_SDL.h $(INC_DIR)/input.h $(INC_DIR)/menu.h
$(OBJ_DIR_SYS)/fonction_SDL.o: $(INC_DIR)/fonction_SDL.h
$(OBJ_DIR_SYS)/input.o: $(INC_DIR)/input.h
$(OBJ_DIR_SYS)/menu.o: $(INC_DIR)/menu.h $(INC_DIR)/fonction_SDL.h

$(OBJ_DIR_SYS)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR_SYS)/.dirstamp
	@echo Building of $(call conv,$@) ...
	@$(CC) -c $< -o $@ $(CFLAGS)
	@echo Building done !

.PRECIOUS: %/.dirstamp
%/.dirstamp:
	@echo Building missing directory .stamp of $(call conv,$@) ...
	@$(MK_DIR) $(call conv,${@D}) &
	@$(TOUCH) $(call conv,$@) &
	@echo Building done !

$(BIN_DIR_SYS)/.dirstamp:
	@echo Building missing directory .stamp of $(call conv,$@) ...
	@$(MK_DIR) $(call conv,${@D}) &
	@$(TOUCH) $(call conv,$@) &
	@$(COPY) $(call conv,$(SDL_DLL)/*.dll) $(call conv,${@D}) &
	@echo Building done !

.PHONY: clean
clean:
	@echo Removing all .o files from $(call conv,$(OBJ_DIR_SYS)) ...
	@$(RM_FILE) $(call conv,$(OBJ_DIR_SYS)/)*.o
	@echo Removing done !

.PHONY: mrproper
mrproper: clean
	@echo Removing directory $(call conv,$(OBJ_DIR)) and $(call conv,$(BIN_DIR)) ...
	@$(RM_DIR) $(call conv,$(OBJ_DIR))
	@$(RM_DIR) $(call conv,$(BIN_DIR))
	@echo Removing done !

.PHONY: run
run:
	@echo Running $(call conv,$(EXEC)) ...
	@./$(EXEC)