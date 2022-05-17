cmd_/home/tyb/os_lab/lab1/Module.symvers := sed 's/ko$$/o/' /home/tyb/os_lab/lab1/modules.order | scripts/mod/modpost -m -a   -o /home/tyb/os_lab/lab1/Module.symvers -e -i Module.symvers   -T -
