morse : check morse.c
	@gcc -o morse morse.c
	@echo "morse has compiled"

clean : 
	rm morse
	clear

check :
	@if command -v aplay >/dev/null; then\
		echo "Aplay found"; \
	else \
		echo "Aplay cannot be found and installation will start"; \
		sudo apt-get install -y alsa-utils; \
	fi
