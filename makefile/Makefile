#通配符：“*”，“?”和“[...]”
#转义字符“\”
obj_by_test := main.o
test :$(obj_by_test)
	gcc -o test $(obj_by_test)
	@ echo "link ok!"
main.o: main.c main.h
	gcc -c main.c
	@ echo "complie ok!"
	@ pwd

A = $(B)
B = $(A)

include a.mk b.mk
#include前面加—表示mk文件不存在也不会报错。
-include c.mk
#include e.mk



.PHONY :clean
clean:
	-rm test $(obj_by_test) 
	cd subsystem && rm subsystem main.o

.PHONY :subsystem
subsystem :
	export obj_by_test
	cd subsystem && $(MAKE)

.PHONY :autovar
autovar : main.c main.h
	@ echo "$\@: "$@
	@ echo "$\%: "$%
	@ echo "$\<: "$<
	@ echo "$\?: "$?
	@ echo "$\^: "$^
	@ echo "$\+: "$+
	@ echo "$\*: "$*
.PHONY :function
comma:= ,
empty:=
space:= $(empty) $(empty)
foo:= a b c
bar:= $(subst $(space),$(comma),$(foo))
function :
	@ echo $(bar)


         

