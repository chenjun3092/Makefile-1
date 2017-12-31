#Copyright (c) 2017 华清远见(广州分中心)-171201
#
#Makefile示例

# $(notdir $(CURDIR)) 获取目录名，notdir:Make函数
TARGET = $(notdir $(CURDIR)) 

CROSS_COMPILE = gcc
COMPILE.c = $(CROSS_COMPILE)  -c
LINK.c = $(CROSS_COMPILE)
RM =rm

# $(wildcard src/*.c) ：获取src/ 目录下的所有.c文件。wildcard:Make函数
SOURCES = $(wildcard src/*.c)
HEADERS = $(wildcard inc/*.h)

# 静态模式规则。OBJFILES下的所有.c 替换成 .o文件
OBJFILES = $(SOURCES:%.c=%.o)


.PHONY:clean all install

all:$(TARGET) 
	@echo builded target:$^
	@echo 
$(TARGET): $(OBJFILES) 
	@echo 
	@echo Linking $@ from $^...
	$(LINK.c) -o $@ $^ 
	@echo Link finished

$(OBJFILES): %.o:%.c $(HEADERS)
	@echo
	@echo Compiling $@ from $<...
	$(COMPILE.c) -o $@ $<
	@echo Compile finished

clean:
	@echo Removing generated files...
	@ -$(RM) -rf $(OBJFILES) $(TARGET) $(EXEC_DIR) *~ *.d *.o 
