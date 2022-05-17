cmd_/home/tyb/os_lab/lab1/modules.order := {   echo /home/tyb/os_lab/lab1/hello.ko; :; } | awk '!x[$$0]++' - > /home/tyb/os_lab/lab1/modules.order
