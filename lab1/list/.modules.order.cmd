cmd_/home/tyb/os_lab/lab1/list/modules.order := {   echo /home/tyb/os_lab/lab1/list/listOfName.ko; :; } | awk '!x[$$0]++' - > /home/tyb/os_lab/lab1/list/modules.order
