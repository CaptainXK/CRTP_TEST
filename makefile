.PHONY:clean check_obj_dir

CC := g++
OBJ_DIR := obj
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS) )
INC := -I.
CLASS_MODE := -DCRTP
CPPFLAGS := -O3 $(CLASS_MODE)


test.app:check_obj_dir $(OBJS)
	$(CC) $(INC) $(OBJS) -o $@ -g $(CPPFLAGS)


check_obj_dir:
	@if test ! -d $(OBJ_DIR);\
		then\
		mkdir $(OBJ_DIR);\
	fi


$(OBJ_DIR)/%.o:%.cpp
	$(CC) $(INC) -c $< -o $@ -g $(CPPFLAGS)


test:test.app
	$(EXEC) ./test.app


clean:
	rm -r $(OBJ_DIR)/*.o *.app