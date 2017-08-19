
CPPFLAGS += -fPIC #编译的时候自动加上-fPIC
CC:=g++
src:=$(shell find *.cpp)
obj:=$(src:.cpp=.o)
dep:=$(src:.cpp=.d)

target:=libbox.so #编译一个动态库

all: $(target)

-include $(dep)

%.d:%.cpp
	$(CC) -MM $< > $@

$(target): $(obj) #生成动态库
	$(CC) -fPIC -shared $^ -o $@

.PHONY:clean install uninstall
clean:
	rm -rf *.o *.d *.so

install:
	mkdir /usr/include/box
	cp *.h /usr/include/box
	cp *.so /usr/lib

uninstall:
	rm -rf /usr/include/box
	rm -rf /usr/lib/libbox.so
