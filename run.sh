if [ "$1" == "bonus" ]; then
	make bonus && ./bonus_mrtest.out
else
	make && ./mrtest.out $@
fi
